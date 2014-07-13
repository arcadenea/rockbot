#include "weapon_edit.h"
#include "ui_weapon_edit.h"

#include "common.h"

weapon_edit::weapon_edit(QWidget *parent) :
QWidget(parent),
ui(new Ui::weapon_edit), _selected_weapon(0), _loaded(false)
{
	ui->setupUi(this);
	reload_weapon_list();
    common::fill_weapons_combo(ui->weapon_select_combo);
    common::fill_projectiles_combo(ui->weapon_projectile_type);
	_loaded = true;
}

weapon_edit::~weapon_edit()
{
    delete ui;
}

void weapon_edit::reload()
{
    _loaded = false;
    _selected_weapon = 0;
    reload_weapon_list();
    common::fill_weapons_combo(ui->weapon_select_combo);
    common::fill_projectiles_combo(ui->weapon_projectile_type);
    _loaded = true;
}

void weapon_edit::reload_weapon_list()
{
    common::fill_weapons_combo(ui->weapon_select_combo);
}

void weapon_edit::on_weapon_select_combo_currentIndexChanged(int index)
{
    _loaded = false;
    _selected_weapon = index;
	ui->weapon_name->setText(QString(game_data.weapons[_selected_weapon].name));
	ui->weapon_damage->setValue(game_data.weapons[_selected_weapon].damage);
    std::cout << "weapon.projectile_id: " << game_data.weapons[_selected_weapon].id_projectile << std::endl;
    ui->weapon_projectile_type->setCurrentIndex(game_data.weapons[_selected_weapon].id_projectile+1); // +1 because of the -1 default projectile
    _loaded = true;
}

void weapon_edit::on_weapon_name_textChanged(const QString &arg1)
{
    if (_loaded == false) {
        return;
    }
    std::cout << "on_weapon_name_textChanged - _selected_weapon: " << _selected_weapon << ", new name: " << arg1.toStdString() << std::endl;
    sprintf(game_data.weapons[_selected_weapon].name, "%s", arg1.toStdString().c_str());
}

void weapon_edit::on_weapon_projectile_type_currentIndexChanged(int index)
{
    if (_loaded == false) {
        return;
    }
    std::cout << ">> on_weapon_projectile_type_currentIndexChanged - _selected_weapon: " << _selected_weapon << ", index: " << index << std::endl;
    game_data.weapons[_selected_weapon].id_projectile = index-1; //-1 is because default weapon (-1)
}

void weapon_edit::on_weapon_damage_valueChanged(int arg1)
{
    if (_loaded == false) {
        return;
    }
    game_data.weapons[_selected_weapon].damage = arg1;
}

