// ITEM Made by player(小林光一:xlgy) /data/item/x/xlgy-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 19 11:51:46 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("长剑[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;36m离[1;31m火[1;36m玄[1;37m冰[1;36m玉[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：小林光一(xlgy)
");
	set("value", 2000000);
	set("point", 123);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
