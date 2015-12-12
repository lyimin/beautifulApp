//
//  EGORefreshTableHeaderView.h
//  Demo
//
//  Created by Devin Doty on 10/14/09October14.
//  Copyright 2009 enormego. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

typedef enum{
	CMPullRefreshPulling = 0,
	CMPullRefreshNormal,
	CMPullRefreshLoading,	
} CMPullRefreshState;

@protocol CMRefreshTableHeaderDelegate;

@interface CMRefreshTableHeaderView : UIView {
	
	id _delegate;
	CMPullRefreshState _state;

	UILabel *_lastUpdatedLabel;
	UILabel *_statusLabel;
	CALayer *_arrowImage;
	UIActivityIndicatorView *_activityView;
	

}

@property (nonatomic,readonly) UILabel *lastUpdatedLabel;

@property (nonatomic,readonly) UILabel *statusLabel;

@property (nonatomic,readonly) CALayer *arrowImage;

@property (nonatomic,readonly) UIActivityIndicatorView *activityView;

@property(nonatomic,assign) id <CMRefreshTableHeaderDelegate> delegate;

- (id)initWithFrame:(CGRect)frame arrowImage:(UIImage *)arrow textColor:(UIColor *)textColor;

- (void)refreshLastUpdatedDate;
- (void)refreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)refreshScrollViewDidEndDragging:(UIScrollView *)scrollView;
- (void)refreshScrollViewDataSourceDidFinishedLoading:(UIScrollView *)scrollView;

@end

@protocol CMRefreshTableHeaderDelegate

- (void)refreshTableHeaderDidTriggerRefresh:(CMRefreshTableHeaderView*)view;
- (BOOL)refreshTableHeaderDataSourceIsLoading:(CMRefreshTableHeaderView*)view;

@optional

- (NSDate*)refreshTableHeaderDataSourceLastUpdated:(CMRefreshTableHeaderView*)view;

@end
