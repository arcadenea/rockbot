#include "object_tab.h"
#include "ui_object_tab.h"
#include "common.h"

object_tab::object_tab(QWidget *parent) :
    QWidget(parent),
	ui(new Ui::object_tab),
	_current_object(0),
	_data_loaded(false)
{
    ui->setupUi(this);

}

object_tab::~object_tab()
{
    delete ui;
}

void object_tab::reload()
{
    _current_object = 0;
    fill_data();
}

void object_tab::fill_data()
{
    _data_loaded = false;
    common::fill_files_combo("data/images/sprites/objects", ui->graphicfile_combo);
    ui->object_preview_area->set_graphicfile(FILEPATH+std::string("/data/images/sprites/objects/")+std::string(game_data.objects[0].graphic_filename));
    ui->object_preview_area->repaint();

    common::fill_object_combo(ui->objectlist_combo);
    _data_loaded = true;
    on_objectlist_combo_currentIndexChanged(0);
}

void object_tab::on_graphicfile_combo_currentIndexChanged(const QString &arg1)
{
	if (_data_loaded == false) {
		return;
	}
	sprintf(game_data.objects[_current_object].graphic_filename, "%s", arg1.toStdString().c_str());
    ui->object_preview_area->set_graphicfile(FILEPATH+std::string("/data/images/sprites/objects/")+arg1.toStdString());
    ui->object_preview_area->repaint();
}

void object_tab::on_objectlist_combo_currentIndexChanged(int index)
{
	if (_data_loaded == false) {
		return;
	}
	_current_object = index;
	ui->name->setText(game_data.objects[index].name);
	ui->graphicfile_combo->setCurrentIndex(ui->graphicfile_combo->findText(QString(game_data.objects[index].graphic_filename)));
	ui->graphic_w->setValue(game_data.objects[index].size.width);
	ui->graphic_h->setValue(game_data.objects[index].size.height);
	ui->type_combo->setCurrentIndex(game_data.objects[index].type);
	ui->timer->setValue(game_data.objects[index].timer);
	ui->speed->setValue(game_data.objects[index].speed);
	ui->limit->setValue(game_data.objects[index].limit);
	ui->animate_on_active_checkbox->setChecked(!game_data.objects[_current_object].animation_auto_start);
	ui->animation_loop_checkbox->setChecked(game_data.objects[_current_object].animation_loop);
	ui->frame_duration_spinbox->setValue(game_data.objects[index].frame_duration);
	ui->animation_reverse_checkbox->setChecked(game_data.objects[_current_object].animation_reverse);
}

void object_tab::on_add_new_pushbutton_clicked()
{
	for (int i=0; i<GAME_MAX_OBJS; i++) {
		if (game_data.objects[i].id == -1) {
			game_data.objects[i].id = i;
			QString temp_str = QString("[") + QString::number(i) + QString("]") + QString("New Object");
			ui->objectlist_combo->addItem(temp_str);
			ui->objectlist_combo->setCurrentIndex(i);
			return;
		}
	}
}

void object_tab::on_name_textChanged(const QString &arg1)
{
    if (_data_loaded == false) { return; }
	sprintf(game_data.objects[_current_object].name, "%s", arg1.toStdString().c_str());
	ui->objectlist_combo->setItemText(_current_object, QString(game_data.objects[_current_object].name));
}

void object_tab::on_type_combo_currentIndexChanged(int index)
{
	if (_data_loaded == false) {
		return;
	}
	game_data.objects[_current_object].type = index;
}

void object_tab::on_limit_valueChanged(int arg1)
{
    if (_data_loaded == false) { return; }
	game_data.objects[_current_object].limit = arg1;
}

void object_tab::on_graphic_w_valueChanged(int arg1)
{
    if (_data_loaded == false) { return; }
	ui->object_preview_area->set_grid_w(arg1);
	game_data.objects[_current_object].size.width = arg1;
}

void object_tab::on_graphic_h_valueChanged(int arg1)
{
    if (_data_loaded == false) { return; }
	ui->object_preview_area->set_grid_h(arg1);
	game_data.objects[_current_object].size.height = arg1;
}

void object_tab::on_speed_valueChanged(int arg1)
{
    if (_data_loaded == false) { return; }
	game_data.objects[_current_object].speed = arg1;
}

void object_tab::on_animate_on_active_checkbox_toggled(bool checked)
{
    if (_data_loaded == false) { return; }
	game_data.objects[_current_object].animation_auto_start = !checked;
}

void object_tab::on_animation_loop_checkbox_toggled(bool checked)
{
    if (_data_loaded == false) { return; }
	game_data.objects[_current_object].animation_loop = checked;
}

void object_tab::on_frame_duration_spinbox_valueChanged(int arg1)
{
    if (_data_loaded == false) { return; }
	game_data.objects[_current_object].frame_duration = arg1;
}

void object_tab::on_animation_reverse_checkbox_toggled(bool checked)
{
    if (_data_loaded == false) { return; }
	game_data.objects[_current_object].animation_reverse = checked;
}

void object_tab::on_timer_valueChanged(int arg1)
{
    if (_data_loaded == false) { return; }
    game_data.objects[_current_object].timer = arg1;
}
