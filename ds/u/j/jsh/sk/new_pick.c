#include <ansi.h> 
#define SKILL_NAME "開鎖技巧[野]"
inherit SKILL;

int do_pick(object me,string arg)
{
        mapping doors;
        string *dirs, dir, key, dest;
        int i,sk,power;
        object *inv, env,obj;

        if( !arg ) return notify_fail("你要開什麼鎖﹖\n");
        env = environment(me);
        if(!env) return 0;
        if(me->is_busy()) return notify_fail("你的上一個動作還沒完成。\n");
        if(me->query("mp")<10) return notify_fail("你精神不佳，無法集中注意力來開鎖。\n");
        if(obj=present(arg, env))
        {
                if(obj->is_box())
                {
                        switch(obj->query_cover_status())
                        {
                                case COVER_NONE : return notify_fail(obj->name()+"並沒有地方可以讓你開鎖。\n");
                                case COVER_OPENED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"已經是開著的啦。\n");
                                case COVER_SMASHED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"都已經壞了還開什麼鎖?!\n");
                        }
                        switch(obj->query_lock_status())
                        {
                                case LOCK_NONE : return notify_fail(obj->name()+"並沒有地方可以讓你開鎖。\n");
                                case LOCK_OPENED : return notify_fail(obj->name()+"的"+obj->query("cover_name")+"並沒有上鎖。\n");
                                case COVER_SMASHED : return notify_fail(obj->name()+"的鎖已經壞了無法打開。\n");
                        }
                        
                        sk=me->query_skill("pick_lock");
                        power=random(2+sk/10);
                        if(power>9) power=9;
                        if(power >= obj->query_lock_level())
                        {
                                if(obj->open_lock())
                                {
                                        me->receive_damage("mp",5+power);
                                                                                message_vision("『..喀啦!!』$N成功\的將$n的鎖打開了。\n",me,obj);
                                        me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                                        return 1;
                                } else return notify_fail("『..啪!!』你似乎把"+obj->name()+"的鎖給弄壞了。\n");
                        } else
                        {
                                me->receive_damage("mp",5+power);
                                message_vision("$N努力的想把$n的鎖打開，但是失敗了。\n",me,obj);
                                obj->pick_lock_fail(me,arg); //可以有失敗的代價
                                me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
                                return 1;
                        }
                } else return notify_fail("那個東西沒有辦法讓你開鎖。\n");
        }
        doors = env->query_doors();
        if( mapp(doors) )
        {
                dirs = keys(doors);
                if( member_array(arg, dirs)!=-1 ) dir = arg;
                else for(i=0; i<sizeof(dirs); i++)
                        if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 )
                        {
                                dir = dirs[i];
                                break;
                        }
                if( !dir ) return notify_fail("這個方向沒有門。\n");
                //key=env->query_door(dir,"key");
                //if(!key ) return notify_fail("這個門並沒有上鎖!\n");
                        
                if( doors[dir]["status"] == DOOR_SMASHED )
                        return notify_fail("這個" + doors[dir]["name"] + "已經壞了。\n");
                if( doors[dir]["status"] == DOOR_OPENED  )
                        return notify_fail( doors[dir]["name"] + "已經是開著的了。\n");
                if( !(doors[dir]["status"] == DOOR_LOCKED)  ) 
                        return notify_fail(doors[dir]["name"] + "並沒有上鎖。\n");
                if( env->query("no_pick") ) return notify_fail(doors[dir]["name"] + "的鎖是特製的你不會開。\n");
                i=env->query("pick_level");
                power=1+random(40+me->query_skill("pick_lock"))-i;
                if(power >= 30)
                {
                        if(env->unlock_door(dir))
                        {
                                me->receive_damage("mp",5+power/8);
                                message_vision("『..喀.啦!!.』"+"$N成功\的將" + doors[dir]["name"] + "的鎖打開了。\n", me);
                                                                me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                                return 1;
                        }
                        
                }else
                {
                                me->receive_damage("mp",5+power/8);
                                message_vision("$N努力的想把" + doors[dir]["name"] + "的鎖打開，但是失敗了。\n",me);
                                env->pick_lock_fail(me,dir); //可以有失敗的代價
                                me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
                                return 1;
                }
        } else return notify_fail("這裡沒有門。\n");
        return 0;
}
 

