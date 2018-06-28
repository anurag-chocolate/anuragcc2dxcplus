/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/


#include <ui/UIButton.h>
#include "HelloWorldScene.h"
#include "VdopiaAdNativeAPI.h"
#include "SimpleAudioEngine.h"
#define buttonTextFontSize 12
#define buttonHeight 30
#define buttonWidth 120
#define selecedColor Color3B(199,140,295)
#define normalTextColor Color3B(100,50,300)
#define LoadInterestialAdButtonTag 01
#define LoadInterestialAdButton1Tag 01

float xPosition=190;
float x1Position=190;

float buttonYPosition=190;
float buttonY1Position=90;



USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    setAdRequestUserParams("23", "23/11/1990", "m", "single", "Asian", "999",
                           "123123", "421340", "321321", "12313");
    setAdRequestAppParams("Vdopia", "Vdopia", "Vdopia-demo.com",
                          "vdopia.com", "", "Movie");

    CCLOG("loadRewardAdFunction");
    //const char *apiKey = "0DqXTL";
    prefetchInterstitialAd("0DqXTL");

    auto loadInterstitialAdButtonBg = cocos2d::LayerColor::create(Color4B(255, 255, 255, 255));
    loadInterstitialAdButtonBg->setPosition(Vec2(xPosition, buttonYPosition));
    loadInterstitialAdButtonBg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(loadInterstitialAdButtonBg,1, LoadInterestialAdButtonTag);
    auto loadInterstitialAdButton = cocos2d::ui::Button::create();
    loadInterstitialAdButton->setPosition(Vec2(60, 13));
    loadInterstitialAdButton->setScale9Enabled(true);
    loadInterstitialAdButton->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    loadInterstitialAdButton->setTitleFontSize(buttonTextFontSize);
    loadInterstitialAdButton->setTitleText("Click to load the ad");
    loadInterstitialAdButton->setTitleColor(normalTextColor);
    loadInterstitialAdButton->setPressedActionEnabled(true);
    loadInterstitialAdButtonBg->addChild(loadInterstitialAdButton, 1, LoadInterestialAdButtonTag);


    loadInterstitialAdButton->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {

                    CCLOG("button clicked");

                    loadInterstitialAd("0DqXTL");


                }
            });


    auto loadInterstitialAdButton1Bg = cocos2d::LayerColor::create(Color4B(255, 255, 255, 255));
    loadInterstitialAdButton1Bg->setPosition(Vec2(x1Position, buttonY1Position));
    loadInterstitialAdButton1Bg->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    this->addChild(loadInterstitialAdButton1Bg,1, LoadInterestialAdButton1Tag);
    auto loadInterstitialAdButton1 = cocos2d::ui::Button::create();
    loadInterstitialAdButton1->setPosition(Vec2(60, 13));
    loadInterstitialAdButton1->setScale9Enabled(true);
    loadInterstitialAdButton1->setContentSize(cocos2d::Size(buttonWidth, buttonHeight));
    loadInterstitialAdButton1->setTitleFontSize(buttonTextFontSize);
    loadInterstitialAdButton1->setTitleText("Click to see the ad");
    loadInterstitialAdButton1->setTitleColor(normalTextColor);
    loadInterstitialAdButton1->setPressedActionEnabled(true);
    loadInterstitialAdButton1Bg->addChild(loadInterstitialAdButton1, 1, LoadInterestialAdButton1Tag);


    loadInterstitialAdButton1->addTouchEventListener(
            [](Ref *pSender, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED) {

                    CCLOG("button clicked");
                    showInterstitialAd();




                }
            });


    return true;
}

/*-----Interstitial methods----*/


void HelloWorld::interstitialAdFailed() {
    CCLOG("Int failed");


}

void HelloWorld::interstitialAdClicked() {
    CCLOG("Int clicked");

}

void HelloWorld::interstitialAdShown() {
    CCLOG("Int shown");
    prefetchInterstitialAd("0DqXTL");
}

void HelloWorld::interstitialAdDismissed() {
    CCLOG("Int Dismmiseed");

}

void HelloWorld::interstitialAdLoaded()  {
    CCLOG("Int Loaddd");


}


/*-------------*/



void HelloWorld::rewardAdFailed() {
    CCLOG("rewardAdFailed");

}
void HelloWorld::rewardAdLoaded() {
    CCLOG("loaded");

}

void HelloWorld::rewardAdCompleted() {
    CCLOG("rewardAdCompleted");

}

void HelloWorld::rewardAdShown() {
    CCLOG("rewardAdShown");;
}

void HelloWorld::rewardAdShownError() {
    CCLOG("rewardAdShownError");

}

void HelloWorld::rewardAdDismissed() {
    CCLOG("rewardAdDismissed");


}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
