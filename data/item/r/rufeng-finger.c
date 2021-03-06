// ITEM Made by player(江湖术士:rufeng) /data/item/r/rufeng-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 31 09:12:28 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m魔光环[2;37;0m", ({ "finger" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;36m离[1;31m火[1;36m玄[1;37m冰[1;36m玉[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：江湖术士(rufeng)
");
	set("value", 2000000);
	set("point", 141);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m装备[1;31m魔光环[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m魔光环[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
