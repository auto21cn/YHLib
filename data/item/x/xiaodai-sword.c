// ITEM Made by player(С��:xiaodai) /data/item/x/xiaodai-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr 26 12:13:46 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mС���Ľ�[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�С��(xiaodai)
");
	set("value", 2000000);
	set("point", 114);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
