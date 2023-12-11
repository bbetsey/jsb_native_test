#import <Foundation/Foundation.h>

@interface NativeCallClass: NSObject
- (void)callNative: (void (^)(void))cb;
@end

@implementation NativeCallClass
- (void)callNative: (void (^)(void))cb {
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        // some work
		sleep(2);
		dispatch_async(dispatch_get_main_queue(), ^{
			cb();
		});
	});
}
@end


// Call from JavaScript
/*

	jsb.reflection.callStaticMethod('NativeCallClass', 'callNative:', function() {
	console.log('Async task completed');
	});

*/


