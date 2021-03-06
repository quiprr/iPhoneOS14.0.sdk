//
//  MTLResourceStatePass.h
//  Metal
//
//  Created by Rini Patel on 2/27/20.
//  Copyright © 2020 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Metal/MTLDefines.h>


#import <Metal/MTLTypes.h>

NS_ASSUME_NONNULL_BEGIN
@protocol MTLDevice;

@protocol MTLCounterSampleBuffer;
#define MTLCounterDontSample ((NSUInteger)-1)
#define MTLMaxResourceStatePassSampleBuffers 4

MTL_EXPORT API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst)
@interface MTLResourceStatePassSampleBufferAttachmentDescriptor : NSObject<NSCopying>
/*!
@property sampleBuffer
@abstract The sample buffer to store samples for the resourceState-pass defined samples.
If sampleBuffer is non-nil, the sample indices will be used to store samples into
the sample buffer.  If no sample buffer is provided, no samples will be taken.
If any of the sample indices are specified as MTLCounterDontSample, no sample
will be taken for that action.
*/
@property (nullable, nonatomic, retain) id<MTLCounterSampleBuffer> sampleBuffer;

/*!
 @property startOfEncoderSampleIndex
 @abstract The sample index to use to store the sample taken at the start of
 command encoder processing.  Setting the value to MTLCounterDontSample will cause
 this sample to be omitted.
 @discussion On devices where MTLCounterSamplingPointAtStageBoundary is unsupported,
 this sample index is invalid and must be set to MTLCounterDontSample or creation of a resourceState pass will fail.
 */
@property (nonatomic) NSUInteger startOfEncoderSampleIndex;
/*!
 @property endOfEncoderSampleIndex
 @abstract The sample index to use to store the sample taken at the end of
 Command encoder processing.  Setting the value to MTLCounterDontSample will cause
 this sample to be omitted.
 @discussion On devices where MTLCounterSamplingPointAtStageBoundary is unsupported,
 this sample index is invalid and must be set to MTLCounterDontSample or creation of a resourceState pass will fail.
 */
@property (nonatomic) NSUInteger endOfEncoderSampleIndex;
@end

MTL_EXPORT API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst)
@interface MTLResourceStatePassSampleBufferAttachmentDescriptorArray : NSObject
/* Individual attachment state access */
- (MTLResourceStatePassSampleBufferAttachmentDescriptor *)objectAtIndexedSubscript:(NSUInteger)attachmentIndex;

/* This always uses 'copy' semantics.  It is safe to set the attachment state at any legal index to nil, which resets that attachment descriptor state to default vaules. */
- (void)setObject:(nullable MTLResourceStatePassSampleBufferAttachmentDescriptor *)attachment atIndexedSubscript:(NSUInteger)attachmentIndex;

@end

/*!
 @class MTLResourceStatePassDescriptor
 @abstract MTLResourceStatePassDescriptor represents a collection of attachments to be used to create a concrete resourceState command encoder
 */
MTL_EXPORT API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst)
@interface MTLResourceStatePassDescriptor : NSObject <NSCopying>

/*!
 @method resourceStatePassDescriptor
 @abstract Create an autoreleased default frame buffer descriptor
 */
+ (MTLResourceStatePassDescriptor *)resourceStatePassDescriptor;


/*!
 @property sampleBufferAttachments
 @abstract An array of sample buffers and associated sample indices.
 */
@property (readonly) MTLResourceStatePassSampleBufferAttachmentDescriptorArray * sampleBufferAttachments API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, macCatalyst);

@end

NS_ASSUME_NONNULL_END
