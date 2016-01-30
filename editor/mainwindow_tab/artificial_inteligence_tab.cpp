#include "artificial_inteligence_tab.h"
#include "ui_artificial_inteligence_tab.h"
#include "common.h"
#include "mediator.h"

extern Mediator *dataExchanger;

artificial_inteligence_tab::artificial_inteligence_tab(QWidget *parent) :
    QWidget(parent),
	ui(new Ui::artificial_inteligence_tab),
	_filling_data(true)
{
    ui->setupUi(this);
    fill_next_combos();
    fill_data(0);
}



artificial_inteligence_tab::~artificial_inteligence_tab()
{
    delete ui;
}

void artificial_inteligence_tab::reload()
{
    _filling_data = true;
    fill_next_combos();
    fill_data(0);
    _filling_data = false;
}



void artificial_inteligence_tab::on_ai_selector_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	_filling_data = true;

	dataExchanger->current_ai = index;
	std::string temp(game_data.ai_types[index].name);
	ui->ai_name->setText(temp.c_str());
	// CHANCES

	ui->chance1->setValue(game_data.ai_types[index].states[0].chance);
	ui->chance2->setValue(game_data.ai_types[index].states[1].chance);
	ui->chance3->setValue(game_data.ai_types[index].states[2].chance);
	ui->chance4->setValue(game_data.ai_types[index].states[3].chance);
    ui->chance5->setValue(game_data.ai_types[index].states[4].chance);
    ui->chance6->setValue(game_data.ai_types[index].states[5].chance);
    ui->chance7->setValue(game_data.ai_types[index].states[6].chance);
    ui->chance8->setValue(game_data.ai_types[index].states[7].chance);
    // ACTIONS
	int action1 = game_data.ai_types[index].states[0].action;
	int action2 = game_data.ai_types[index].states[1].action;

	ui->action1->setCurrentIndex(game_data.ai_types[index].states[0].action);
	ui->action2->setCurrentIndex(game_data.ai_types[index].states[1].action);
	ui->action3->setCurrentIndex(game_data.ai_types[index].states[2].action);
	ui->action4->setCurrentIndex(game_data.ai_types[index].states[3].action);
    ui->action5->setCurrentIndex(game_data.ai_types[index].states[4].action);
    ui->action6->setCurrentIndex(game_data.ai_types[index].states[5].action);
    ui->action7->setCurrentIndex(game_data.ai_types[index].states[6].action);
    ui->action8->setCurrentIndex(game_data.ai_types[index].states[7].action);
    ui->near_action->setCurrentIndex(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.x+1);
    ui->hit_action->setCurrentIndex(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.x+1);
    ui->dead_action->setCurrentIndex(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.x+1);


    /*
    for (int i=0; i<4; i++) {
        change_action(i, game_data.ai_types[index].states[i].action);
    }
    */

	// OPTIONS
	common::fill_ai_options_combo(game_data.ai_types[index].states[0].action, ui->parameter1);
	common::fill_ai_options_combo(game_data.ai_types[index].states[1].action, ui->parameter2);
    common::fill_ai_options_combo(game_data.ai_types[index].states[2].action, ui->parameter3);
	common::fill_ai_options_combo(game_data.ai_types[index].states[3].action, ui->parameter4);
    common::fill_ai_options_combo(game_data.ai_types[index].states[4].action, ui->parameter5);
    common::fill_ai_options_combo(game_data.ai_types[index].states[5].action, ui->parameter6);
    common::fill_ai_options_combo(game_data.ai_types[index].states[6].action, ui->parameter7);
    common::fill_ai_options_combo(game_data.ai_types[index].states[7].action, ui->parameter8);
    common::fill_ai_options_combo(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.x, ui->near_extra_parameter);
    common::fill_ai_options_combo(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.x, ui->hit_extra_parameter);
    common::fill_ai_options_combo(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.x, ui->dead_extra_parameter);

	ui->parameter1->setCurrentIndex(game_data.ai_types[index].states[0].extra_parameter);
    //std::cout << "#0 - AI[" << index << "].states[1].extra_parameter: " << game_data.ai_types[dataExchanger->current_ai].states[1].extra_parameter << std::endl;
	ui->parameter2->setCurrentIndex(game_data.ai_types[index].states[1].extra_parameter);
	ui->parameter3->setCurrentIndex(game_data.ai_types[index].states[2].extra_parameter);
	ui->parameter4->setCurrentIndex(game_data.ai_types[index].states[3].extra_parameter);
    ui->parameter5->setCurrentIndex(game_data.ai_types[index].states[4].extra_parameter);
    ui->parameter6->setCurrentIndex(game_data.ai_types[index].states[5].extra_parameter);
    ui->parameter7->setCurrentIndex(game_data.ai_types[index].states[6].extra_parameter);
    ui->parameter8->setCurrentIndex(game_data.ai_types[index].states[7].extra_parameter);
    ui->near_extra_parameter->setCurrentIndex(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.y);
    ui->hit_extra_parameter->setCurrentIndex(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.y);
    ui->dead_extra_parameter->setCurrentIndex(game_data.game_npcs[index].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.y);

	// go-tos
	ui->next1->setCurrentIndex(game_data.ai_types[index].states[0].go_to);
	ui->next2->setCurrentIndex(game_data.ai_types[index].states[1].go_to);
	ui->next3->setCurrentIndex(game_data.ai_types[index].states[2].go_to);
	ui->next4->setCurrentIndex(game_data.ai_types[index].states[3].go_to);
    ui->next5->setCurrentIndex(game_data.ai_types[index].states[4].go_to);
    ui->next6->setCurrentIndex(game_data.ai_types[index].states[5].go_to);
    ui->next7->setCurrentIndex(game_data.ai_types[index].states[6].go_to);
    ui->next8->setCurrentIndex(game_data.ai_types[index].states[7].go_to);

	// delays
	ui->delay1->setValue(game_data.ai_types[index].states[0].go_to_delay);
	ui->delay2->setValue(game_data.ai_types[index].states[1].go_to_delay);
	ui->delay3->setValue(game_data.ai_types[index].states[2].go_to_delay);
	ui->delay4->setValue(game_data.ai_types[index].states[3].go_to_delay);
    ui->delay5->setValue(game_data.ai_types[index].states[4].go_to_delay);
    ui->delay6->setValue(game_data.ai_types[index].states[5].go_to_delay);
    ui->delay7->setValue(game_data.ai_types[index].states[6].go_to_delay);
    ui->delay8->setValue(game_data.ai_types[index].states[7].go_to_delay);

	_filling_data = false;
}

void artificial_inteligence_tab::fill_data(int index)
{
	// ai selector
	common::fill_ai_list(ui->ai_selector);

	// actions
	common::fill_ai_actions_combo(ui->action1);
	common::fill_ai_actions_combo(ui->action2);
	common::fill_ai_actions_combo(ui->action3);
	common::fill_ai_actions_combo(ui->action4);
    common::fill_ai_actions_combo(ui->action5);
    common::fill_ai_actions_combo(ui->action6);
    common::fill_ai_actions_combo(ui->action7);
    common::fill_ai_actions_combo(ui->action8);
    common::fill_ai_actions_combo(ui->near_action, true);
    common::fill_ai_actions_combo(ui->hit_action, true);
    common::fill_ai_actions_combo(ui->dead_action, true);

	_filling_data = false;
	on_ai_selector_currentIndexChanged(index);
}

void artificial_inteligence_tab::change_action(int index, int action_n)
{
    if (index >= 0) {
        game_data.ai_types[dataExchanger->current_ai].states[index].action = action_n;
        game_data.ai_types[dataExchanger->current_ai].states[index].extra_parameter = 0;
    // -1: near-player, -2: hit, -3: dead
    } else if (index == -1) {
        game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.x = action_n;
    } else if (index == -2) {
        game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.x = action_n;
    } else if (index == -3) {
        game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.x = action_n;
    }
	if (index == 0) {
		common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter1);
	} else if (index == 1) {
		common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter2);
	} else if (index == 2) {
		common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter3);
	} else if (index == 3) {
		common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter4);
    } else if (index == 4) {
        common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter5);
    } else if (index == 5) {
        common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter6);
    } else if (index == 6) {
        common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter7);
    } else if (index == 7) {
        common::fill_ai_options_combo(game_data.ai_types[dataExchanger->current_ai].states[index].action, ui->parameter8);
    } else if (index == -1) {
        common::fill_ai_options_combo(game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.x, ui->near_extra_parameter);
    } else if (index == -2) {
        common::fill_ai_options_combo(game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.x, ui->hit_extra_parameter);
    } else if (index == -3) {
        common::fill_ai_options_combo(game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.x, ui->dead_extra_parameter);
    }
}




void artificial_inteligence_tab::on_ai_name_textChanged(const QString &arg1)
{
	if (_filling_data == true) {
		return;
	}
	sprintf(game_data.ai_types[dataExchanger->current_ai].name, "%s", arg1.toStdString().c_str());
	ui->ai_selector->setItemText(dataExchanger->current_ai, QString("[") + QString::number(dataExchanger->current_ai) + QString("] - ") + arg1);
}

void artificial_inteligence_tab::on_chance1_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[0].chance = arg1;
}

void artificial_inteligence_tab::on_chance2_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[1].chance = arg1;
}

void artificial_inteligence_tab::on_chance3_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[2].chance = arg1;
}

void artificial_inteligence_tab::on_chance4_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[3].chance = arg1;
}


void artificial_inteligence_tab::on_chance5_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[4].chance = arg1;
}

void artificial_inteligence_tab::on_chance6_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[5].chance = arg1;
}

void artificial_inteligence_tab::on_chance7_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[6].chance = arg1;
}

void artificial_inteligence_tab::on_chance8_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[7].chance = arg1;
}

void artificial_inteligence_tab::on_action1_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	change_action(0, index);
}

void artificial_inteligence_tab::on_action2_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	change_action(1, index);
}

void artificial_inteligence_tab::on_action3_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	change_action(2, index);
}

void artificial_inteligence_tab::on_action4_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	change_action(3, index);
}

void artificial_inteligence_tab::on_action5_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(4, index);
}


void artificial_inteligence_tab::on_action6_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(5, index);
}

void artificial_inteligence_tab::on_action7_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(6, index);
}

void artificial_inteligence_tab::on_action8_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(7, index);
}

void artificial_inteligence_tab::on_parameter1_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[0].extra_parameter = index;
}

void artificial_inteligence_tab::on_parameter2_currentIndexChanged(int index)
{
    //std::cout << "AI::on_parameter2_currentIndexChanged - _filling_data: " << _filling_data << std::endl;
	if (_filling_data == true) {
		return;
	}
    //std::cout << "#1 - AI[" << dataExchanger->current_ai << "].states[1].extra_parameter: " << game_data.ai_types[dataExchanger->current_ai].states[1].extra_parameter << std::endl;
    game_data.ai_types[dataExchanger->current_ai].states[1].extra_parameter = index;
    //std::cout << "#2 - AI[" << dataExchanger->current_ai << "].states[1].extra_parameter: " << game_data.ai_types[dataExchanger->current_ai].states[1].extra_parameter << std::endl;

}

void artificial_inteligence_tab::on_parameter3_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[2].extra_parameter = index;
}

void artificial_inteligence_tab::on_parameter4_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[3].extra_parameter = index;
}


void artificial_inteligence_tab::on_parameter5_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[4].extra_parameter = index;
}

void artificial_inteligence_tab::on_parameter6_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[5].extra_parameter = index;
}

void artificial_inteligence_tab::on_parameter7_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[6].extra_parameter = index;
}

void artificial_inteligence_tab::on_parameter8_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[7].extra_parameter = index;
}


void artificial_inteligence_tab::on_next1_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[0].go_to = index;
}

void artificial_inteligence_tab::on_next2_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[1].go_to = index;
}

void artificial_inteligence_tab::on_next3_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[2].go_to = index;
}

void artificial_inteligence_tab::on_next4_currentIndexChanged(int index)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[3].go_to = index;
}




void artificial_inteligence_tab::on_next5_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[4].go_to = index;

}

void artificial_inteligence_tab::on_next6_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[5].go_to = index;

}

void artificial_inteligence_tab::on_next7_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[6].go_to = index;

}

void artificial_inteligence_tab::on_next8_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[7].go_to = index;

}


void artificial_inteligence_tab::on_delay1_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[0].go_to_delay = arg1;
}

void artificial_inteligence_tab::on_delay2_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[1].go_to_delay = arg1;
}

void artificial_inteligence_tab::on_delay3_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
	game_data.ai_types[dataExchanger->current_ai].states[2].go_to_delay = arg1;
}

void artificial_inteligence_tab::on_delay4_valueChanged(int arg1)
{
	if (_filling_data == true) {
		return;
	}
    game_data.ai_types[dataExchanger->current_ai].states[3].go_to_delay = arg1;
}


void artificial_inteligence_tab::on_delay5_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[4].go_to_delay = arg1;

}

void artificial_inteligence_tab::on_delay6_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[5].go_to_delay = arg1;

}

void artificial_inteligence_tab::on_delay7_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[6].go_to_delay = arg1;

}

void artificial_inteligence_tab::on_delay8_valueChanged(int arg1)
{
    if (_filling_data == true) {
        return;
    }
    game_data.ai_types[dataExchanger->current_ai].states[7].go_to_delay = arg1;

}

void artificial_inteligence_tab::fill_next_combos()
{
    fill_next_combo(ui->next1);
    fill_next_combo(ui->next2);
    fill_next_combo(ui->next3);
    fill_next_combo(ui->next4);
    fill_next_combo(ui->next5);
    fill_next_combo(ui->next6);
    fill_next_combo(ui->next7);
    fill_next_combo(ui->next8);
}

void artificial_inteligence_tab::fill_next_combo(QComboBox *combo)
{
    /*
    std::vector<std::string> list = {
        std::string("CHANCE"),
        std::string("#1"),
        std::string("#2"),
        std::string("#3"),
        std::string("#4"),
        std::string("#5"),
        std::string("#6"),
        std::string("#7"),
        std::string("#8")
    };
    */
    std::vector<std::string> list;
    list.push_back("CHANCE");
    list.push_back("#1");
    list.push_back("#2");
    list.push_back("#3");
    list.push_back("#4");
    list.push_back("#5");
    list.push_back("#6");
    list.push_back("#7");
    list.push_back("#8");
    for (int i=0; i<list.size(); i++) {
        std::string temp = list[i];
        QString temp_str = QString("[") + QString::number(i) + QString("] - ") + QString(temp.c_str());
        combo->addItem(temp_str);
    }
}





void artificial_inteligence_tab::on_near_action_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(-1, index-1);
}

void artificial_inteligence_tab::on_hit_action_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(-2, index-1);
}


void artificial_inteligence_tab::on_dead_action_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    change_action(-3, index-1);
}

void artificial_inteligence_tab::on_near_extra_parameter_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][1].colision_rect.y = index;
}

void artificial_inteligence_tab::on_hit_extra_parameter_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][2].colision_rect.y = index;
}

void artificial_inteligence_tab::on_dead_extra_parameter_currentIndexChanged(int index)
{
    if (_filling_data == true) {
        return;
    }
    game_data.game_npcs[dataExchanger->current_ai].sprites[ANIM_TYPE_TELEPORT][3].colision_rect.y = index;
}



