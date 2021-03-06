//
//  MLCReductionLayer.m
//  MLCompute
//
//  Copyright © 2019 Apple. All rights reserved.
//

#import <MLCompute/MLCTypes.h>
#import <MLCompute/MLCLayer.h>

@class MLCDevice;
@class MLCTensor;

NS_ASSUME_NONNULL_BEGIN

/*! @class      MLCReductionLayer
    @abstract   Reduce tensor values across a given dimension to a scalar value.
    @discussion The layer is used to perform reductionType operation on a given dimension.
                Result of this layer is a tensor of the same shape as source tensor,
                except for the given dimension which is set to 1.
 */
MLCOMPUTE_CLASS_AVAILABLE_STARTING(macos(10.16), ios(14.0), tvos(14.0))
@interface MLCReductionLayer : MLCLayer

/*! @property   reductionType
    @abstract   The reduction type
 */
@property (readonly, nonatomic) MLCReductionType reductionType;

/*! @property   dimension
    @abstract   The dimension over which to perform the reduction operation
 */
@property (readonly, nonatomic) NSUInteger dimension;

/*! @abstract Create a reduction layer .
    @param    reductionType        The reduction type.
    @param    dimension          The reduction dimension.
    @return   A new reduction layer.
 */
+ (instancetype _Nullable)layerWithReductionType:(MLCReductionType)reductionType
                                       dimension:(NSUInteger)dimension;

@end

NS_ASSUME_NONNULL_END
