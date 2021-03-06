// ITEM Made by player(月隐无:shadow) /data/item/s/shadow-zhanyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Dec 20 16:11:30 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m月之幻象[2;37;0m", ({ "zhanyi" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[2;37;0m[1;31m阎罗绸[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：月隐无(shadow)
");
	set("value", 2000000);
	set("point", 163);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m装备[1;36m月之幻象[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m月之幻象[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
