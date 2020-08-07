//
//  MenuView.h
//  MenuDemo
//
//  Created by ego on 20/8/7.
//  Copyright © 2020年 ego. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface MenuView : UIView

 
+(instancetype)MenuViewWithDependencyView:(UIView *)dependencyView MenuView:(UIView *)leftmenuView isShowCoverView:(BOOL)isCover;

-(instancetype)initWithDependencyView:(UIView *)dependencyView MenuView:(UIView *)leftmenuView isShowCoverView:(BOOL)isCover;
    

-(void)show;

-(void)hidenWithoutAnimation;
-(void)hidenWithAnimation;

@end
