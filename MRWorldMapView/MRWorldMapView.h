// MRWorldMapView.h
//
// Copyright 2015 Héctor Marqués
//
// This software contains code derived from YBMapView (Yuba)
// Copyright 2011 Sergey Lenkov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#import <UIKit/UIKit.h>

@class MRWorldMapView;


/**
 Protocol for `MRWorldMapView`'s delegate.
 */
@protocol MRWorldMapViewDelegate <NSObject>
@optional

/**
 Notifies that the country with the given `code` has been highlighted.
 
 @param map The world map object informing the delegate about the new highlighted country.
 @param code The country ISO code.
 */
- (void)worldMap:(MRWorldMapView *)map didHighlightCountry:(NSString *)code;

/**
 Notifies that the country with the given `code` has been selected.

 @param map The world map object informing the delegate about the new selected country.
 @param code The country ISO code.
 */
- (void)worldMap:(MRWorldMapView *)map didSelectCountry:(NSString *)code;

/**
 Should return the color to be used as fill color for the country with the given `code`.
 
 @param map The world map object that is making this request.
 @param code The country ISO code.
 @return The `UIColor` to be used as fill color for the country.
 */
- (UIColor *)worldMap:(MRWorldMapView *)map colorForCountry:(NSString *)code;

/**
 Should return the color to be used as fill color for the country with the given `code` when selected.
 
 @param map The world map object that is making this request.
 @param code The country ISO code.
 @return The `UIColor` to be used as fill color for the country when selected.
 */
- (UIColor *)worldMap:(MRWorldMapView *)map selectedColorForCountry:(NSString *)code;

/**
 Should return the color to be used as fill color for the country with the given `code` when highlighted.
 
 @param map The world map object that is making this request.
 @param code The country ISO code.
 @return The `UIColor` to be used as fill color for the country when highlighted.
 */
- (UIColor *)worldMap:(MRWorldMapView *)map highlightedColorForCountry:(NSString *)code;

@end


IB_DESIGNABLE

/**
 `UIView` subclass that displays a world map with selectable countries.
 */
@interface MRWorldMapView : UIView {
    CGPoint _highlightPoint;
    CGPoint _selectPoint;
}

/**
 The dictionary with the world map data.
 */
@property (nonatomic, strong) NSMutableDictionary *map;

/**
 Use this for adjusting the horizontal ratio to your map data.
 */
@property (nonatomic, assign) IBInspectable NSInteger horizontalRatioDivisor;

/**
 Use this for adjusting the verticat ratio to your map data.
 */
@property (nonatomic, assign) IBInspectable NSInteger verticalRatioDivisor;

/**
 The horizontal padding between the world map and the view's borders.
 */
@property (nonatomic, assign) IBInspectable CGFloat mapHorizontalPadding;

/**
 Color used for creating the background gradient.
 */
@property (nonatomic, strong) IBInspectable UIColor *backgroundGradientColor;

/**
 Inset for the background gradient.
 */
@property (nonatomic, assign) IBInspectable UIEdgeInsets backgroundGradientInset;

/**
 Default country fill color.
 */
@property (nonatomic, strong) IBInspectable UIColor *countryColor;

/**
 Country border color.
 */
@property (nonatomic, strong) IBInspectable UIColor *countryBorderColor;

/**
 Default highlighted country fill color.
 */
@property (nonatomic, strong) IBInspectable UIColor *highlightedColor;

/**
 Highlighted country border color.
 */
@property (nonatomic, strong) IBInspectable UIColor *highlightedBorderColor;

/**
 Default selected country fill color.
 */
@property (nonatomic, strong) IBInspectable UIColor *selectedColor;

/**
 Selected country border color.
 */
@property (nonatomic, strong) IBInspectable UIColor *selectedBorderColor;

/**
 Selected country border shadow color.
 */
@property (nonatomic, strong) IBInspectable UIColor *selectedShadowColor;

/**
 Selected country border shadow offset.
 
 You should provide the shadow offset inverted, because of the transform applied to the view.
 */
@property (nonatomic, assign) IBInspectable CGSize selectedShadowOffset;

/**
 Selected country border shadow blur.
 */
@property (nonatomic, assign) IBInspectable CGFloat selectedShadowBlur;

/**
 Currently highlighted country code.
 */
@property (nonatomic, strong) IBInspectable NSString *highlightedCountry;

/**
 Currently selected country code.
 */
@property (nonatomic, strong) IBInspectable NSString *selectedCountry;

/**
 Delegate that will be notified when the selected or highlighted countries change.
 */
@property (nonatomic, assign) IBOutlet id <MRWorldMapViewDelegate> delegate;

@end
