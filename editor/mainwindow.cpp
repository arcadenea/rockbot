#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "defines.h"
#include "addwizard.h"
#include "dialognpcedit.h"
#include "dialogobjectedit.h"
#include "loadgamepicker.h"
#include "dialog_pick_color.h"
#include "stage_swap_dialog.h"
//#include <QStandardItemModel>
#include <QListView>
#include <QList>
#include <QListWidgetItem>
#include "../defines.h"



#include "common.h"

extern Mediator *dataExchanger;
extern char EDITOR_FILEPATH[512];
extern std::string FILEPATH;

extern CURRENT_FILE_FORMAT::file_game game_data;
extern CURRENT_FILE_FORMAT::file_stages stage_data;

bool background_filled = false;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), _npcedit_tab_selectednpc(0), _data_loading(false)
{
	ui->setupUi(this);
	dataExchanger->loadGame(1);
	// add maps to the list

    //QStandardItem games("GAMES");

    //QStandardItem npcs("NPCs");
    //npcs.setEditable(FALSE);
    //QStandardItem npc1("NPC 001");
    //npc1.setEditable(FALSE);
    //npcs.appendRow(&npc1);

    //model.appendRow(&games);
    //model.appendRow(&npcs);
    //model.setHeaderData(0, Qt::Horizontal, "Item List");

	// insert NPC tab form
	npc_edit_tab = new npc_edit();
	ui->npc_tab->layout()->addWidget(npc_edit_tab);

	// insert AI tab form
	ai_edit_tab = new artificial_inteligence_tab();
	ui->ai_tab->layout()->addWidget(ai_edit_tab);

	// insert OBJECT tab form
	object_edit_tab = new object_tab();
	ui->object_tab->layout()->addWidget(object_edit_tab);


	// insert OBJECT tab form
	weapon_edit_tab = new weapon_edit();
	ui->weapon_edit_tab->layout()->addWidget(weapon_edit_tab);

	// insert STAGE tab form
	stage_edit_tab = new stage_edit();
	ui->stage_tab->layout()->addWidget(stage_edit_tab);

    // insert PROJECTILE tab form
    projectile_edit_tab = new projectile_edit();
	ui->tab_projectiles->layout()->addWidget(projectile_edit_tab);


	// insert COLORCYCLE tab form
	colorcycle_edit_tab = new colorcycle_edit();
	ui->colorcycle_tab->layout()->addWidget(colorcycle_edit_tab);

    // insert GAME_PROPERTIES tab form
    game_prop_tab = new game_properties_tab();
    ui->game_tab->layout()->addWidget(game_prop_tab);

    map_edit_tab = new map_tab();
    ui->maps_tab->layout()->addWidget(map_edit_tab);


    player_edit_tab = new player_edit();
    ui->player_tab->layout()->addWidget(player_edit_tab);
}

MainWindow::~MainWindow()
{
	delete ui;
}









void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionSave_triggered()
{
    map_edit_tab->save();
}

void MainWindow::on_actionOpen_triggered()
{
	QDialog *open = new loadGamePicker;
	open->show();
	//dataExchanger->loadGame();
    //map_edit_tab->update_edit_area();
}

void MainWindow::on_pallete_signalPalleteChanged()
{
	printf("DEBUG on_pallete_signalPalleteChanged\n");
}

/*
void MainWindow::on_addNpcButton_clicked()
{
	printf("DEBUG.MainWindow::on_addNpcButton_clicked - NpcAddNumber: '%d'\n", dataExchanger->NpcAddNumber);
	dataExchanger->editMode = EDITMODE_ADDNPC;
}
*/




void MainWindow::on_actionNew_triggered()
{
	dataExchanger->createGame();
}


// ------------------- EDIT BUTTONS --------------------- //



void MainWindow::on_actionLock_Edit_triggered()
{
	if (ui->actionLock_Edit->isChecked()) {
		ui->actionNormal_Edit->setChecked(FALSE);
		ui->actionEraser->setChecked(FALSE);
		ui->actionFill->setChecked(FALSE);
		ui->actionLink->setChecked(FALSE);
		ui->actionStairs->setChecked(FALSE);
        map_edit_tab->set_current_box(2);
        dataExchanger->editTool = EDITMODE_LOCK;
	// to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
	} else {
		ui->actionLock_Edit->setChecked(TRUE);
	}
}

void MainWindow::on_actionNormal_Edit_triggered()
{
	if (ui->actionNormal_Edit->isChecked()) {
		ui->actionLock_Edit->setChecked(FALSE);
		ui->actionEraser->setChecked(FALSE);
		ui->actionFill->setChecked(FALSE);
		ui->actionLink->setChecked(FALSE);
		ui->actionStairs->setChecked(FALSE);
		dataExchanger->editTool = EDITMODE_NORMAL;
        if (ui->actionEdit_Tileset->isChecked()) {
            map_edit_tab->set_current_box(1);
        } else if (ui->actionEdit_NPC->isChecked()) {
            map_edit_tab->set_current_box(3);
        } else if (ui->actionAdd_Object->isChecked()) {
            map_edit_tab->set_current_box(5);
        }
	// to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
	} else {
		ui->actionNormal_Edit->setChecked(TRUE);
	}
}

void MainWindow::on_actionEraser_triggered()
{
	if (ui->actionEraser->isChecked()) {
		ui->actionLock_Edit->setChecked(FALSE);
		ui->actionNormal_Edit->setChecked(FALSE);
		ui->actionFill->setChecked(FALSE);
		ui->actionLink->setChecked(FALSE);
		ui->actionStairs->setChecked(FALSE);
		dataExchanger->editTool = EDITMODE_ERASER;
	// to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
	} else {
		ui->actionEraser->setChecked(TRUE);
	}
}




void MainWindow::on_actionFill_triggered()
{
	if (ui->actionFill->isChecked()) {
		ui->actionLock_Edit->setChecked(FALSE);
		ui->actionNormal_Edit->setChecked(FALSE);
		ui->actionEraser->setChecked(FALSE);
		ui->actionLink->setChecked(FALSE);
		ui->actionStairs->setChecked(FALSE);
		dataExchanger->editTool = EDITMODE_FILL;
	// to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
	} else {
		ui->actionFill->setChecked(TRUE);
	}
}


void MainWindow::on_MainWindow_iconSizeChanged(QSize iconSize)
{
	Q_UNUSED (iconSize);
	saveGeometry();
}

void MainWindow::on_actionLink_triggered()
{
    map_edit_tab->set_current_box(4);
	if (ui->actionLink->isChecked()) {
		ui->actionLock_Edit->setChecked(FALSE);
		ui->actionNormal_Edit->setChecked(FALSE);
		ui->actionEraser->setChecked(FALSE);
		ui->actionFill->setChecked(FALSE);
		ui->actionStairs->setChecked(FALSE);
		ui->actionAdd_Object->setChecked(FALSE);
		dataExchanger->editTool = EDITMODE_LINK;
        map_edit_tab->update_edit_area();
	// to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
	} else {
		ui->actionFill->setChecked(TRUE);
        map_edit_tab->update_edit_area();
	}
}


void MainWindow::on_actionStairs_triggered()
{
	if (ui->actionStairs->isChecked()) {
		ui->actionNormal_Edit->setChecked(FALSE);
		ui->actionEraser->setChecked(FALSE);
		ui->actionFill->setChecked(FALSE);
		ui->actionLock_Edit->setChecked(FALSE);
		ui->actionLink->setChecked(FALSE);
		ui->actionAdd_Object->setChecked(FALSE);
		dataExchanger->editTool = EDITMODE_STAIRS;
	// to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
	} else {
		ui->actionStairs->setChecked(TRUE);
	}
    map_edit_tab->update_edit_area();
}


void MainWindow::on_actionAdd_Object_triggered()
{
    map_edit_tab->set_current_box(5);
	ui->actionEdit_Tileset->setChecked(FALSE);
	ui->actionEdit_NPC->setChecked(FALSE);
	ui->actionNormal_Edit->setChecked(TRUE);
	ui->actionEraser->setChecked(FALSE);
	ui->actionFill->setChecked(FALSE);
	ui->actionLock_Edit->setChecked(FALSE);
	ui->actionLink->setChecked(FALSE);
	ui->actionAdd_Object->setChecked(TRUE);
	dataExchanger->editMode = EDITMODE_OBJECT;
	dataExchanger->editTool = EDITMODE_NORMAL;
    // to make things simpler, we do not allow "uncheck" of the tool, you must pick another one to uncheck
    map_edit_tab->update_edit_area();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
	dataExchanger->layerLevel = index+1;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_actionEdit_NPC_triggered()
{
    map_edit_tab->set_current_box(3);
	ui->actionEdit_Tileset->setChecked(FALSE);
	ui->actionAdd_Object->setChecked(FALSE);
	ui->actionEdit_NPC->setChecked(TRUE);
	ui->actionFill->setDisabled(TRUE);
	ui->actionLink->setDisabled(TRUE);
	ui->actionLock_Edit->setDisabled(TRUE);
	ui->actionStairs->setDisabled(TRUE);
	dataExchanger->editMode = EDITMODE_NPC;
}

void MainWindow::on_actionEdit_Tileset_triggered()
{
	ui->actionEdit_NPC->setChecked(FALSE);
	ui->actionAdd_Object->setChecked(FALSE);
	ui->actionEdit_Tileset->setChecked(TRUE);
	ui->actionFill->setDisabled(FALSE);
	ui->actionLink->setDisabled(FALSE);
	ui->actionLock_Edit->setDisabled(FALSE);
	ui->actionStairs->setDisabled(FALSE);
    map_edit_tab->set_current_box(1);
	dataExchanger->editMode = EDITMODE_NORMAL;
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
	printf(">>>> MainWindow::on_listWidget_currentRowChanged, row: %d\n", currentRow);
	dataExchanger->selectedNPC = currentRow;
}

void MainWindow::on_editNPCButton_clicked()
{
	dataExchanger->editModeNPC = 1;
	QDialog *npc_editor = new DialogNPCEdit;
	npc_editor->show();
	QObject::connect(npc_editor, SIGNAL(finishedNPCEditor()), this, SLOT(reloadComboItems()));
}


void MainWindow::on_actionOne_triggered()
{
    dataExchanger->layerLevel = 1;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_actionTwo_triggered()
{
    dataExchanger->layerLevel = 2;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_actionThree_triggered()
{
    dataExchanger->layerLevel = 3;
    map_edit_tab->update_edit_area();
}




void MainWindow::on_toolBox_currentChanged(int index)
{
	Q_UNUSED (index);
	dataExchanger->selectedNPC = -1;
}


void MainWindow::on_listWidget_2_currentRowChanged(int currentRow)
{
	dataExchanger->terrainType = currentRow+1;
}

void MainWindow::on_spinBox_valueChanged(int value)
{
        dataExchanger->zoom = value;
}

void MainWindow::on_link_orientation_combobox_currentIndexChanged(int index)
{
	dataExchanger->link_type = index;
}

void MainWindow::on_npc_direction_combo_currentIndexChanged(int index)
{
	dataExchanger->npc_direction = index;
}





void MainWindow::on_pushButton_2_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_player_color1()));
}



void MainWindow::on_pushButton_7_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_player_keycolor1()));
}

void MainWindow::on_pushButton_8_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_player_keycolor2()));
}

void MainWindow::on_pushButton_9_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_player_keycolor3()));
}


void MainWindow::on_comboBox_6_currentIndexChanged(int index)
{
	dataExchanger->current_player = index;
}

void MainWindow::on_pushButton_3_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_player_color2()));
}

void MainWindow::on_pushButton_4_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_player_color3()));
}





void MainWindow::on_tabWidget_currentChanged(int index)
{
    dataExchanger->selectedNPC = 0;
	dataExchanger->currentMap = 0;
	dataExchanger->currentGame = 0;
	dataExchanger->currentStage = 0;
	dataExchanger->current_player = 0;
	dataExchanger->current_weapon = 0;
    game_prop_tab->reload();
    colorcycle_edit_tab->reload();
    projectile_edit_tab->reload();
    stage_edit_tab->reload();
    weapon_edit_tab->reload();
    object_edit_tab->reload();
    ai_edit_tab->reload();
    npc_edit_tab->reload();
    map_edit_tab->reload();
}






void MainWindow::on_actionSet_Boss_triggered(bool checked)
{
    if (checked == true) {
        map_edit_tab->set_current_box(3);
        ui->actionEdit_Tileset->setChecked(FALSE);
        ui->actionAdd_Object->setChecked(FALSE);
        ui->actionEdit_NPC->setChecked(FALSE);
        ui->actionFill->setDisabled(TRUE);
        ui->actionLink->setDisabled(TRUE);
        ui->actionLock_Edit->setDisabled(TRUE);
        ui->actionStairs->setDisabled(TRUE);
        dataExchanger->editMode = EDITMODE_SET_BOSS;
    }
}




void MainWindow::on_bg1_filename_currentIndexChanged(const QString &arg1)
{
	if (arg1.toStdString() == std::string("None")) {
        stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].filename[0] = '\0';
	} else {
        sprintf(stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].filename, "%s", arg1.toStdString().c_str());
	}
    map_edit_tab->update_edit_area();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
	dataExchanger->show_background_color = checked;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_bg1_y_pos_valueChanged(int arg1)
{
    stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].adjust_y = arg1;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_bg1_speed_valueChanged(int arg1)
{
    stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].speed = arg1*10;
    std::cout << "*** on_bg1_speed_valueChanged - setvalue: " << arg1 << ", bg1.speed: " << stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].speed << std::endl;
    map_edit_tab->update_edit_area();
}


void MainWindow::on_bg2_filename_currentIndexChanged(const QString &arg1)
{
	if (arg1.toStdString() == std::string("None")) {
        stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[1].filename[0] = '\0';
	} else {
        sprintf(stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[1].filename, "%s", arg1.toStdString().c_str());
	}
}

void MainWindow::on_bg2_y_pos_valueChanged(int arg1)
{
    stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[1].adjust_y = arg1;
    map_edit_tab->update_edit_area();
}


void MainWindow::on_bg2_speed_valueChanged(int arg1)
{
    stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[1].speed = arg1*10;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_bg_color_pick_clicked()
{
	QDialog *color_pick = new dialog_pick_color;
	color_pick->show();
	QObject::connect(color_pick, SIGNAL(accepted()), this, SLOT(pick_bg_color()));
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
	dataExchanger->show_bg1 = checked;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
	dataExchanger->show_bg2 = checked;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_stage_boss_weapon_combo_currentIndexChanged(int index)
{
    stage_data.stages[dataExchanger->currentStage].boss.id_weapon = index;
}

void MainWindow::on_bg1_speed_valueChanged(double arg1)
{
	if (background_filled == false) {
		return;
	}
    stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].speed = arg1*10;
    std::cout << "*** on_bg1_speed_valueChanged - setvalue: " << arg1 << ", bg1.speed: " << stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].speed << std::endl;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_bg2_speed_valueChanged(double arg1)
{
	if (background_filled == false) {
		return;
	}
    stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[1].speed = arg1*10;
    map_edit_tab->update_edit_area();
}

void MainWindow::on_actionReset_Map_triggered()
{
	for (int i=0; i<MAP_W; i++) {
		for (int j=0; j<MAP_H; j++) {
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].locked = 0;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].tile1.x = -1;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].tile1.y = -1;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].tile2.x = -1;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].tile2.y = -1;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].tile3.x = -1;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].tiles[i][j].tile3.y = -1;
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[0].filename[0] = '\0';
            stage_data.stages[dataExchanger->currentStage].maps[dataExchanger->currentMap].backgrounds[1].filename[0] = '\0';
		}
	}
}

void MainWindow::on_players_tab_maxshots_valueChanged(int arg1)
{
	if (_data_loading == true) {
		return;
	}
	std::cout << "dataExchanger->current_player: " << dataExchanger->current_player << ", max_shots: " << game_data.players[dataExchanger->current_player].max_shots << std::endl;
	game_data.players[dataExchanger->current_player].max_shots = arg1;
	std::cout << "max_shots: " << game_data.players[dataExchanger->current_player].max_shots << std::endl;
}

void MainWindow::on_can_slide_checkbox_toggled(bool checked)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].can_slide = checked;
}

void MainWindow::on_players_tab_jumpgravity_valueChanged(double arg1)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].jump_gravity = arg1;
}

void MainWindow::on_players_tab_fallgravity_valueChanged(double arg1)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].touch_damage_reduction = arg1;
}

void MainWindow::on_players_tab_jumpspeed_valueChanged(double arg1)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].jump_initial_speed = arg1;
}

void MainWindow::on_players_tab_movespeed_valueChanged(int arg1)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].move_speed = arg1;
}

void MainWindow::on_players_tab_hasshield_toggled(bool checked)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].have_shield = checked;
}

void MainWindow::on_players_tab_hp_valueChanged(int arg1)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].HP = arg1;
}

void MainWindow::on_players_tab_name_textChanged(const QString &arg1)
{
    if (_data_loading == true) {
        return;
    }
    sprintf(game_data.players[dataExchanger->current_player].name, "%s", arg1.toStdString().c_str());
}

void MainWindow::on_chargedshot_combo_currentIndexChanged(int index)
{
    if (_data_loading == true) {
        return;
    }
    game_data.players[dataExchanger->current_player].full_charged_projectile_id = index;
}

void MainWindow::on_players_tab_list_combo_2_currentIndexChanged(int index)
{
    dataExchanger->current_player = index;
    std::cout << "MainWindow::on_players_tab_list_combo_2_currentIndexChanged - index: "	 << index << ", max_shots: " << game_data.players[index].max_shots << std::endl;
}

void MainWindow::on_actionSwap_Maps_triggered()
{
    // open swap maps dialog
    QDialog *stage_swap = new stage_swap_dialog;
    stage_swap->show();

}

void MainWindow::on_actionBeaten_toggled(bool arg1)
{
    dataExchanger->show_beaten = arg1;
}
