#include "../LindenbergResearch.hpp"
#include "../LRModel.hpp"


using namespace rack;
using namespace lrt;


struct BlankPanel : LRModule {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
        NUM_INPUTS
    };
    enum OutputIds {
        NUM_OUTPUTS
    };
    enum LightIds {
        NUM_LIGHTS
    };


    BlankPanel() : LRModule(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS) {}
};


/**
 * @brief Blank Panel with Logo
 */
struct BlankPanelWidget : LRModuleWidget {
    BlankPanelWidget(BlankPanel *module);


    void step() override;

};


BlankPanelWidget::BlankPanelWidget(BlankPanel *module) : LRModuleWidget(module) {
    panel->addSVGVariant(LRGestaltType::DARK, APP->window->loadSvg(asset::plugin(pluginInstance, "res/panels/BlankPanel.svg")));
    panel->addSVGVariant(LRGestaltType::LIGHT, APP->window->loadSvg(asset::plugin(pluginInstance, "res/panels/BlankPanelLight.svg")));
    panel->addSVGVariant(LRGestaltType::AGED, APP->window->loadSvg(asset::plugin(pluginInstance, "res/panels/BlankPanelLight.svg")));


    panel->init();
    addChild(panel);
    box.size = panel->box.size;

    float speed = 0.017;

    addChild(SVGRotator::create(Vec(105.5, 55), APP->window->loadSvg(asset::plugin(pluginInstance, "res/elements/CogBig.svg")), speed, 0.7, 0.9));
    addChild(SVGRotator::create(Vec(139, 43.7), APP->window->loadSvg(asset::plugin(pluginInstance, "res/elements/CogMiddle.svg")), speed * 5.9f, 0.7, 0.9));
    addChild(SVGRotator::create(Vec(120, 40), APP->window->loadSvg(asset::plugin(pluginInstance, "res/elements/CogSmall.svg")), -speed * 2.3f, 0.7, 0.9));

}


void BlankPanelWidget::step() {

    /*panel->patinaWidgetClassic->randomize();
    panel->patinaWidgetWhite->randomize();

    panel->dirty = true;*/
    LRModuleWidget::step();
}


Model *modelBlankPanel = createModel<BlankPanel, BlankPanelWidget>("BlankPanel_01");
