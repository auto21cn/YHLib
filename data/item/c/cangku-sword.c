// ITEM Made by player(小包子:cangku) /data/item/c/cangku-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 14 13:39:07 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m末日的审判[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一柄剑。
[1;33m看上去只感觉眼前迷乱，视线模糊。[2;37;0m
剑柄上刻着一行小字：小包子(cangku)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;31m$N目光如剑，一阵阵庄严沉稳的声音渐渐响起，刹那间天地变色，江海狂哮。\n[1;33m当末日到来的时候，我将自己与我的敌人至于正义的天平上，接受远古诸神的裁决。\n[1;32m正义的人，你的灵魂将得到最终的宽恕。[2;37;0m\n");
	set("unwield_msg", "[34m邪恶的人，你的将受到最终的审判。\n[1;31m肉体将在火神的咆哮中毁灭，你的灵魂将在沉寂之海接受最终的痛苦与寂寞。\n[35m声音渐渐完结，眼前的一切，渐渐开始变化，你的视线也渐渐模糊……[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
