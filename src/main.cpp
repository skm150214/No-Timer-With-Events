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
                bottomTextWeCouldMoveToTheCenterBecauseItLooksBetter->setPosition({bottomTextWeCouldMoveToTheCenterBecauseItLooksBetter->getPosition().x,150});
                labelThatIDontKnowHowToDelete->setPosition({0, -9999});
            };
        };
        return true;
    }
};//minimal code :three-stars: :three-stars: :three-stars: