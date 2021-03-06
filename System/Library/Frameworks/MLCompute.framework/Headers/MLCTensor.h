//
//  MLCTensor.h
//  MLCompute
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MLCompute/MLCDefines.h>
#import <MLCompute/MLCTypes.h>

@class MLCDevice;
@class MLCTensorDescriptor;
@class MLCTensorData;

NS_ASSUME_NONNULL_BEGIN

/*! @class      MLCTensor
    @discussion A tensor object
 */
MLCOMPUTE_CLASS_AVAILABLE_STARTING(macos(10.16), ios(14.0), tvos(14.0))
@interface MLCTensor : NSObject<NSCopying>

/*! @property   tensorID
    @abstract   The tensor ID
    @discussion A unique number to identify each tensor.  Assigned when the tensor is created.
 */
@property (readonly, nonatomic) NSUInteger tensorID;

/*! @property   descriptor
    @abstract   The tensor descriptor
 */
@property (readonly, nonatomic, copy) MLCTensorDescriptor *descriptor;

/*! @property   data
    @abstract   The tensor data
*/
@property (readonly, nonatomic, nullable, retain) NSData *data;

/*! @property   label
    @abstract   A string to help identify this object.
 */
@property (readwrite, nonatomic, copy) NSString *label;

/*! @property   device
    @abstract   The device associated with this tensor.
 */
@property (readonly, nonatomic, nullable, retain) MLCDevice *device;

/*! @property   optimizer buffers to use if tensor is used as a parameter
    @abstract   These are the host side optimizer (momentum and velocity) buffers which developers can query and initialize
 */
@property (readonly, nonatomic, retain) NSArray<MLCTensorData *> *optimizerData;


+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*
 * create a tensor with or without data.
 * for example, for weights used by convolution or mean, variance, beta, and gamma parameters
 * with batch normalization will create a tensor with data.
 */

/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object without any data
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithDescriptor:(MLCTensorDescriptor *)tensorDescriptor;

/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object initialized with a random initializer such as Glorot Uniform.
    @param      tensorDescriptor              The tensor descriptor
    @param      randomInitializerType   The random initializer type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithDescriptor:(MLCTensorDescriptor *)tensorDescriptor
               randomInitializerType:(MLCRandomInitializerType)randomInitializerType;


/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object with a MLCTensorData object that specifies the tensor data buffer
    @param      tensorDescriptor              The tensor descriptor
    @param      data                                         The random initializer type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithDescriptor:(MLCTensorDescriptor *)tensorDescriptor
                                data:(MLCTensorData *)data;

#pragma mark - Convenience Methods

/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object without any data.  The tensor data type is MLCDataTypeFloat32.
    @param      shape                           The tensor shape
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithShape:(NSArray<NSNumber *> *)shape
    NS_REFINED_FOR_SWIFT;

/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object initialized with a random initializer such as Glorot Uniform.
                The tensor data type is MLCDataTypeFloat32
    @param      shape                                       The tensor shape
    @param      randomInitializerType   The random initializer type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithShape:(NSArray<NSNumber *> *)shape
          randomInitializerType:(MLCRandomInitializerType)randomInitializerType
    NS_REFINED_FOR_SWIFT;

/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object without any data
    @param      shape                           The tensor shape
    @param      dataType                    The tensor data type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithShape:(NSArray<NSNumber *> *)shape
                       dataType:(MLCDataType)dataType
    NS_REFINED_FOR_SWIFT;

/*! @abstract   Create a MLCTensor object
    @discussion Create a tensor object with data
    @param      shape                           The tensor shape
    @param      data                             The tensor data
    @param      dataType                    The tensor data type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithShape:(NSArray<NSNumber *> *)shape
                           data:(MLCTensorData *)data
                       dataType:(MLCDataType)dataType
    NS_REFINED_FOR_SWIFT;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a NCHW tensor object with tensor data type = MLCDataTypeFloat32
    @param      width                           The tensor width
    @param      height                         The tensor height
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithWidth:(NSUInteger)width
                         height:(NSUInteger)height
            featureChannelCount:(NSUInteger)featureChannelCount
                      batchSize:(NSUInteger)batchSize;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a NCHW tensor object initialized with a scalar value
    @param      width                           The tensor width
    @param      height                         The tensor height
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @param      fillWithData           The scalar value to initialize the tensor data with
    @param      dataType                    The tensor data type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithWidth:(NSUInteger)width
                         height:(NSUInteger)height
            featureChannelCount:(NSUInteger)featureChannelCount
                      batchSize:(NSUInteger)batchSize
                   fillWithData:(float)fillWithData
                       dataType:(MLCDataType)dataType;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a NCHW tensor object initialized with a random initializer type.
                The tensor data type is MLCDataTypeFloat32
    @param      width                                      The tensor width
    @param      height                                    The tensor height
    @param      featureChannelCount                Number of feature channels
    @param      batchSize                              The tensor batch size
    @param      randomInitializerType   The random initializer type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithWidth:(NSUInteger)width
                         height:(NSUInteger)height
            featureChannelCount:(NSUInteger)featureChannelCount
                      batchSize:(NSUInteger)batchSize
          randomInitializerType:(MLCRandomInitializerType)randomInitializerType;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a NCHW tensor object with a tensor data object
                The tensor data type is MLCDataTypeFloat32.
    @param      width                           The tensor width
    @param      height                         The tensor height
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @param      data                             The tensor data
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithWidth:(NSUInteger)width
                         height:(NSUInteger)height
            featureChannelCount:(NSUInteger)featureChannelCount
                      batchSize:(NSUInteger)batchSize
                           data:(MLCTensorData *)data;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a NCHW tensor object with a tensor data object
                The tensor data type is MLCDataTypeFloat32.
    @param      width                           The tensor width
    @param      height                         The tensor height
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @param      data                             The tensor data
    @param      dataType                    The tensor data type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithWidth:(NSUInteger)width
                         height:(NSUInteger)height
            featureChannelCount:(NSUInteger)featureChannelCount
                      batchSize:(NSUInteger)batchSize
                           data:(MLCTensorData *)data
                       dataType:(MLCDataType)dataType;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a tensor typically used by a recurrent layer
                The tensor data type is MLCDataTypeFloat32.
    @param      sequenceLength       The length of sequences stored in the tensor
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithSequenceLength:(NSUInteger)sequenceLength
                     featureChannelCount:(NSUInteger)featureChannelCount
                               batchSize:(NSUInteger)batchSize;


/*! @abstract   Create a MLCTensor  object
    @discussion Create a tensor typically used by a recurrent layer
                The tensor data type is MLCDataTypeFloat32.
    @param      sequenceLength                   The length of sequences stored in the tensor
    @param      featureChannelCount                 Number of feature channels
    @param      batchSize                              The tensor batch size
    @param      randomInitializerType   The random initializer type
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithSequenceLength:(NSUInteger)sequenceLength
                     featureChannelCount:(NSUInteger)featureChannelCount
                               batchSize:(NSUInteger)batchSize
                   randomInitializerType:(MLCRandomInitializerType)randomInitializerType;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a tensor typically used by a recurrent layer
                The tensor data type is MLCDataTypeFloat32.
    @param      sequenceLength       The length of sequences stored in the tensor
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @param      data                             The tensor data
    @return     A new MLCTensorData object
 */
+ (instancetype)tensorWithSequenceLength:(NSUInteger)sequenceLength
                     featureChannelCount:(NSUInteger)featureChannelCount
                               batchSize:(NSUInteger)batchSize
                                    data:(MLCTensorData * _Nullable)data;


/*! @abstract   Create a MLCTensor  object
    @discussion Create a tensor of variable length sequences typically used by a recurrent layer
                The tensor data type is MLCDataTypeFloat32.
    @param      sequenceLengths                 An array of sequence lengths
    @param      sortedSequences                 A flag to indicate if the sequence lengths are sorted.  If yes, they must be sorted in descending order
    @param      featureChannelCount                 Number of feature channels
    @param      batchSize                              The tensor batch size
    @param      randomInitializerType   The random initializer type
    @return     A new MLCTensorData object
 */
+ (instancetype _Nullable)tensorWithSequenceLengths:(NSArray<NSNumber *> *)sequenceLengths
                                    sortedSequences:(BOOL)sortedSequences
                                featureChannelCount:(NSUInteger)featureChannelCount
                                          batchSize:(NSUInteger)batchSize
                              randomInitializerType:(MLCRandomInitializerType)randomInitializerType
    NS_REFINED_FOR_SWIFT;

/*! @abstract   Create a MLCTensor  object
    @discussion Create a tensor of variable length sequences typically used by a recurrent layer
                The tensor data type is MLCDataTypeFloat32.
    @param      sequenceLengths     An array of sequence lengths
    @param      sortedSequences     A flag to indicate if the sequence lengths are sorted.  If yes, they must be sorted in descending order
    @param      featureChannelCount     Number of feature channels
    @param      batchSize                  The tensor batch size
    @param      data                             The tensor data
    @return     A new MLCTensorData object
 */
+ (instancetype _Nullable)tensorWithSequenceLengths:(NSArray<NSNumber *> *)sequenceLengths
                                    sortedSequences:(BOOL)sortedSequences
                                featureChannelCount:(NSUInteger)featureChannelCount
                                          batchSize:(NSUInteger)batchSize
                                               data:(MLCTensorData * _Nullable)data
    NS_REFINED_FOR_SWIFT;


/*! @abstract   Check a tensor for NaN or INF values
    @return     Returns YES if a NaN or INF is found; otherwise returns NO
 */
@property (readonly, nonatomic) BOOL hasValidNumerics;


/*! @abstract   Specify the host side optimizer buffers to use
    @discussion These spcify the momentum, velocity vectors that will be used by the optimizer
                The developer can specify these buffers.  If not, MLCompute will allocate them
                This need to saved/restored by the developer in order to continue training from a checkpoint
    @param optimizerData    The user specified buffers
    @return     Returns YES if success, NO if there is a failure.
 */
- (BOOL)optimizerData:(NSArray<MLCTensorData *> *)optimizerData;


/*! @abstract   Synchronize the data in host memory.
    @discussion Synchronize the data in host memory i.e. tensor.data with latest contents in device memory
                This should only be called once the graph that this tensor is used with has finished execution;
                Otherwise the results in device memory may not be up to date.
                NOTE:  This method should not be called from a completion callback when device is the GPU.
    @return     Returns YES if success, NO if there is a failure to synchronize
 */
- (BOOL)synchronizeData;


/*! @abstract   Copy tensor data from device memory to user specified memory
    @discussion Before copying tensor data from device memory, one may need to synchronize the device memory for example
                when device is the GPU.  The synchronizeWithDevice argumet can be set appropraitely to indicate this.
                For CPU this is ignored.  If the tensor has been specified in outputs of a graph using addOutputs,
                synchronizeWithDevice should be set to NO.
                NOTE:  This method should only be called once the graph that this tensor is used with has finished execution;
                Otherwise the results in device memory may not be up to date.  synchronizeWithDevice must be set to NO
                when this method is called from a completion callback for GPU.
    @param bytes                                     The user specified data in which to copy
    @param length                                   The size in bytes to copy
    @param synchronizeWithDevice  Whether to synchronize device memory if device is GPU
    @return     Returns YES if success, NO if there is a failure to synchronize
 */
- (BOOL)copyDataFromDeviceMemoryToBytes:(void *)bytes
                                 length:(NSUInteger)length
                  synchronizeWithDevice:(BOOL)synchronizeWithDevice;

/*! @abstract   Associates the given data to the tensor. If the device is GPU, also copies the data to the device memory.
                Returns true if the data is successfully associated with the tensor and copied to the device.
    @discussion The caller must guarantee the lifetime of the underlying memory of \p data for the entirety of the tensor's
                lifetime.
    @param      data             The data to associated with the tensor
    @param      device           The compute device
    @return     A Boolean value indicating whether the data is successfully associated with the tensor and copied to the device.
*/
- (BOOL)bindAndWriteData:(MLCTensorData *)data
                toDevice:(MLCDevice *)device;

@end

NS_ASSUME_NONNULL_END
