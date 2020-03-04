// test.c

inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	object ob;
	if(!arg) return notify_fail("要測試啥?\n");
	ob = present(arg, environment(me));
	if(!ob) return notify_fail("沒有這個生物..\n");
	if(userp(ob)) return notify_fail("不可對玩家使用..\n");
	if(!ob->is_character()) return notify_fail("沒有這個生物..\n");
//	SKILL_D("celestial")->hit_ob(me, ob, 50, 20);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
    printf("wizard level: %d   status: %s\n", wiz_level(ob), wizhood(ob));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : test <某人>

用來測試武功技能的強弱。
HELP
    );
    return 1;
}
