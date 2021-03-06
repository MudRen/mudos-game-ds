// exert.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string skill_name, func_name, target, toward;
        object tar;

        seteuid(getuid());
        if( me->is_ghost() )
                return notify_fail(" 你現在還是鬼魂吧。\n");
        if( me->is_busy() || me->is_block() )
                return notify_fail("( 你上一個動作還沒有完成﹐不能施展技能或武功\。)\n");
        if( environment(me)->query("no_exert") )
                return notify_fail("這裡不准使用特殊技能。\n");
        if( !arg )
                return notify_fail("指令格式﹕exert <技能或武學>[.武學招術] [on <施展對象>]或[at <施展方向>]\n");
        // 參數方式:
        // 1. exert skill_name.func_name on/at target/toward
        // 2. exert skill_name on/at target/toward
        // 3. exert skill_name func_name
        if( sscanf(arg, "%s on %s", skill_name, target) == 2 )
        {
                tar = present(target, environment(me));
                if( !tar ) tar = present(target, me);
                if( !tar ) return notify_fail("這裡沒有 "+target+"。\n");
                sscanf(skill_name, "%s.%s", skill_name, func_name);
        }
        else if( sscanf(arg, "%s at %s", skill_name, toward) == 2 )
        {
                if( stringp(target=environment(me)->query("exits/"+toward)))
                {
                        tar = load_object(target);
                        sscanf(skill_name, "%s.%s", skill_name, func_name);
                }
                else return notify_fail("這個方向不能施展技能或武學。("+skill_name+")\n");
        }
        else if( sscanf(arg, "%s %s", skill_name, func_name) != 2 )
        {
                skill_name = arg;
                tar = 0;
        }

        if( me->query_skill(skill_name) > 0)
                return (int)SKILL_D(skill_name)->exert(me, tar, func_name);
        else return notify_fail("你還沒學過此技能或武學。("+skill_name+")\n");
}

int help(object me)
{
        write(@HELP
指令格式﹕exert <技能或武學> [on <施展對象>]或[at <施展方向>]

指令格式﹕
1. exert <技能或武學>.<招數名> [on <施展對象>]或[at <施展方向>]
2. exert <技能或武學> [on <施展對象>]或[at <施展方向>]
3. exert <技能或武學> <武學招數>
 
使用技能﹐你必需要指定<武學或技能名稱>﹐<對象>及<方向>的需要與否
則視技能之功能而定。

在你施展某一個武功或技能之前﹐你必須學過此武學或是技能。
 
HELP
        );
        return 1;
}
