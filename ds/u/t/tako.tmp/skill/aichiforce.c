inherit SKILL;


int valid_enable(string usage)
{
        return (usage=="force");
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的氣或內力不夠﹐不能練太極心法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你盤腿而坐照著心法運起太極心法。\n");

        return 1;
x
}
string exert_function_file(string func)
{
    return CLASS_D("taichi") + "/taichiforce/" + func;
}

