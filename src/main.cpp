#include <Geode/Geode.hpp>
using namespace geode::prelude;
#include <Geode/modify/DailyLevelPage.hpp>
class $modify(DailyLevelPage) {
    bool init(GJTimedLevelType type) {
        if (!DailyLevelPage::init(type)) {
            return false;
        }
        if (type != GJTimedLevelType::Event) return true;
        auto nodeWhereWeFindTheLabel=(this->getChildByIDRecursive("DailyLevelNode"));
        if (nodeWhereWeFindTheLabel){
            auto labelThatIDontKnowHowToDelete=(nodeWhereWeFindTheLabel->getChildByIDRecursive("time-label"));
            if (labelThatIDontKnowHowToDelete){
                auto bottomTextWeCouldMoveToTheCenterBecauseItLooksBetter=(getChildByIDRecursive("time-label"));
                if (Mod::get()->getSettingValue<bool>("move-bottom-text")){
                    bottomTextWeCouldMoveToTheCenterBecauseItLooksBetter->setPosition({bottomTextWeCouldMoveToTheCenterBecauseItLooksBetter->getPosition().x,m_mainLayer->getContentHeight() / 2});
                };
                labelThatIDontKnowHowToDelete->setVisible(false);
            };
        };
        return true;
    }
};//minimal code :three-stars: :three-stars: :three-stars: 
