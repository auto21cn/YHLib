// ITEM Made by player(̫����:real) /data/item/r/real-ldlh.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 14 21:47:43 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m�����ֻ�[2;37;0m", ({ "ldlh" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣�̫����(real)
");
	set("value", 2000000);
	set("point", 127);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
