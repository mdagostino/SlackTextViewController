//
//   Copyright 2014 Slack Technologies, Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>

/** Generic protocol needed when customizing your own typing indicator view. */
@protocol SLKTypingIndicatorProtocol <NSObject>
@required

/**
 Returns YES if the indicator is visible.
 SLKTextViewController depends on this property internally, by observing its value changes to update the typing indicator view's constraints automatically.
 You can simply @synthesize this property to make it KVO compliant, or override its setter method and wrap its implementation with -willChangeValueForKey: and -didChangeValueForKey: methods, for more complex KVO compliance.
 */
@property (nonatomic, getter = isVisible) BOOL visible;

/**
 Returns the natural size for the receiving view, considering only properties of the view itself.
 SLKTextViewController uses Auto-Layout internally, so this API is the most appropriate way to update the view dimensions dynamically.
 You can return UIViewNoIntrinsicMetric for any intrinsic size of a given dimension.
 */
- (CGSize)intrinsicContentSize;

@optional

/**
 Dismisses the indicator view.
 */
- (void)dismissIndicator;

@end