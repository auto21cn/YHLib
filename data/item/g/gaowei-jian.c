// ITEM Made by player(月影岚:gaowei) /data/item/g/gaowei-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 14 18:05:11 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m苍白的正义[2;37;0m", ({ "jian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一柄剑。
[1;32m着是采陨星之铁，受众神所譬佑的正义之剑，剑身古拙淡雅，周身满被雕琢奇异的罡文符号。在白银的剑托上，被镂入了一行文字。[1;37m尔等即如神，能辩善与恶。[2;37;0m
剑柄上刻着一行小字：月影岚(gaowei)
");
	set("value", 4200000);
	set("point", 554);
	set("material", "tian jing");
	set("wield_msg", "[1;31m$N一拳击入大地，庄严而沉稳的声音慢慢响起。\n[1;32m召唤埋藏于血脉中的远古圣器。\n[1;32m失落的神之力呀，我在此企求传承。\n[1;32m为世人所赞颂的美好生命为代价。\n[1;32m瞬间达到至高的颠峰……[2;37;0m\n");
	set("unwield_msg", "[35m$N长叹一声，手中之剑融入空气，消失不见。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
