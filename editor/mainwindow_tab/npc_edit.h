#ifndef NPC_EDIT_H
#define NPC_EDIT_H

#include <QWidget>

namespace Ui {
    class npc_edit;
}

class npc_edit : public QWidget
{
    Q_OBJECT

public:
    explicit npc_edit(QWidget *parent = 0);
    ~npc_edit();
    void reload();

private slots:
	void on_npc_edit_tab_selectnpccombo_currentIndexChanged(int index);

	void on_npc_edit_tab_graphiccombo_currentIndexChanged(const QString &arg1);

	void on_npc_edit_tab_graphicwidth_valueChanged(int arg1);

	void on_npc_edit_tab_graphicheight_valueChanged(int arg1);

	void on_npc_edit_tab_NpcName_textChanged(const QString &arg1);

	void on_npc_edit_tab_NpcHP_valueChanged(int arg1);

	void on_npc_edit_tab_canshoot_toggled(bool checked);

	void on_npc_edit_tab_shieldtype_currentIndexChanged(int index);

	void on_npc_edit_tab_iatype_currentIndexChanged(int index);

	void on_npc_edit_tab_movespeed_valueChanged(int arg1);

	void on_npc_edit_tab_range_valueChanged(int arg1);

	void on_npc_edit_tab_frametype_currentIndexChanged(int index);

	void on_bg_graphic_combo_currentIndexChanged(const QString &arg1);

	void on_npc_edit_tab_weakness_list_currentIndexChanged(int index);

	void on_npc_edit_tab_weakness_points_valueChanged(int arg1);

	void on_frame_list_selector_currentIndexChanged(int index);

	void reload_frame_list(int index);

    void on_pushButton_clicked();

    void on_frameUp_clicked();

    void on_frameDown_clicked();

    void on_frameList_listWidget_currentRowChanged(int currentRow);

    void on_sprite_duration_spinBox_valueChanged(int arg1);

	void on_sprite_colision_x_valueChanged(int arg1);

	void on_sprite_colision_y_valueChanged(int arg1);

	void on_sprite_colision_w_valueChanged(int arg1);

	void on_sprite_colision_h_valueChanged(int arg1);

    void on_projectile1_comboBox_currentIndexChanged(int index);

    void on_projectile2_comboBox_currentIndexChanged(int index);

	void on_ai_chain_currentIndexChanged(int index);

	void on_isBoss_checkBox_toggled(bool checked);

    void on_sprite_pos_x_valueChanged(int arg1);

    void on_sprite_pos_y_valueChanged(int arg1);

    void on_checkBox_toggled(bool checked);

    void on_hitarea_x_spinBox_valueChanged(int arg1);

    void on_hitarea_y_spinBox_valueChanged(int arg1);

    void on_hitarea_w_spinBox_valueChanged(int arg1);

    void on_hitarea_h_spinBox_valueChanged(int arg1);

    void on_isSubBoss_checkbox_toggled(bool checked);

    void on_respawn_time_spinBox_valueChanged(int arg1);

    void on_AddFrame_Button_clicked();

private:
	void fill_data();

public slots:
	void set_npc_frame();


private:
    Ui::npc_edit *ui;
	int _npcedit_tab_selectednpc;
	int _npcedit_tab_selected_weakness_weapon;
	bool _data_loading; // prevents "on_change" happening while data is being filled in
    bool _ignore_spritelist_row_changed;
};

#endif // NPC_EDIT_H
