# MenuView
左滑弹出菜单视图

例如：
/********************************************/
- (MenuView *)menuView {
    //侧边个人中心菜单
    if (!_menuView) {
        weak_self
        
        _menuView = [MenuView MenuViewWithDependencyView:self.view MenuView:self.myCenterVC.view isShowCoverView:YES];
        _myCenterVC.didSelectedBlock = ^{
            [weakSelf.menuView hidenWithAnimation];
        };
    }
    return _menuView;
}

- (MyCenterViewController *)myCenterVC {
    if (!_myCenterVC) {
        _myCenterVC = [[MyCenterViewController alloc] init];
        [_myCenterVC.view setFrame:CGRectMake(0, 0, SCREEN_WIDTH * 0.8, SCREEN_HEIGHT)];
    }
    return _myCenterVC;
}
/********************************************/

MyCenterViewController 用于在菜单视图上添加业务

@property (nonatomic, copy) void (^didSelectedBlock) (void);

跳转如下：
-(void)pushVC:(UIViewController *)vc{
    if (self.didSelectedBlock) {
        self.didSelectedBlock();
    }
   [(UIViewController *)ZYDetaileProcessing.getCurrentVC push:vc animation:YES andIsHiddenTabbar:YES];
}

/**
 获取当前屏幕显示的viewcontroller
 
 @return .
 */
+ (UIViewController *)getCurrentVC;

+ (UIViewController *)getCurrentVC
{
    UIViewController *rootViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
    UIViewController *currentVC = [self getCurrentVCFrom:rootViewController];
    return currentVC;
    
    
}

+ (UIViewController *)getCurrentVCFrom:(UIViewController *)rootVC
{
    UIViewController *currentVC;
    if ([rootVC presentedViewController]) {
        // 视图是被presented出来的
        rootVC = [rootVC presentedViewController];
   
    }
    if ([rootVC isKindOfClass:[UITabBarController class]]) {
        // 根视图为UITabBarController
        currentVC = [self getCurrentVCFrom:[(UITabBarController *)rootVC selectedViewController]];
    } else if ([rootVC isKindOfClass:[UINavigationController class]]){
        // 根视图为UINavigationController
        currentVC = [self getCurrentVCFrom:[(UINavigationController *)rootVC visibleViewController]];
  
    } else {
        // 根视图为非导航类
        currentVC = rootVC;
  
    }
    return currentVC;
}

