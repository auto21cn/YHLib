// ITEM Made by player(С��:xiaodai) /data/item/x/xiaodai-belt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 10:29:52 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m������¥[2;37;0m", ({ "belt" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
����Ե�Ͽ���һ��С�֣�С��(xiaodai)
");
	set("value", 2000000);
	set("point", 120);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;32m������¥[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;32m������¥[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
