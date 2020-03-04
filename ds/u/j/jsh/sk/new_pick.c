#include <ansi.h> 
#define SKILL_NAME "�}��ޥ�[��]"
inherit SKILL;

int do_pick(object me,string arg)
{
        mapping doors;
        string *dirs, dir, key, dest;
        int i,sk,power;
        object *inv, env,obj;

        if( !arg ) return notify_fail("�A�n�}������S\n");
        env = environment(me);
        if(!env) return 0;
        if(me->is_busy()) return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
        if(me->query("mp")<10) return notify_fail("�A�믫���ΡA�L�k�����`�N�O�Ӷ}��C\n");
        if(obj=present(arg, env))
        {
                if(obj->is_box())
                {
                        switch(obj->query_cover_status())
                        {
                                case COVER_NONE : return notify_fail(obj->name()+"�èS���a��i�H���A�}��C\n");
                                case COVER_OPENED : return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�w�g�O�}�۪��աC\n");
                                case COVER_SMASHED : return notify_fail(obj->name()+"��"+obj->query("cover_name")+"���w�g�a�F�ٶ}������?!\n");
                        }
                        switch(obj->query_lock_status())
                        {
                                case LOCK_NONE : return notify_fail(obj->name()+"�èS���a��i�H���A�}��C\n");
                                case LOCK_OPENED : return notify_fail(obj->name()+"��"+obj->query("cover_name")+"�èS���W��C\n");
                                case COVER_SMASHED : return notify_fail(obj->name()+"����w�g�a�F�L�k���}�C\n");
                        }
                        
                        sk=me->query_skill("pick_lock");
                        power=random(2+sk/10);
                        if(power>9) power=9;
                        if(power >= obj->query_lock_level())
                        {
                                if(obj->open_lock())
                                {
                                        me->receive_damage("mp",5+power);
                                                                                message_vision("�y..�ذ�!!�z$N���\\���N$n���ꥴ�}�F�C\n",me,obj);
                                        me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                                        return 1;
                                } else return notify_fail("�y..��!!�z�A���G��"+obj->name()+"���굹���a�F�C\n");
                        } else
                        {
                                me->receive_damage("mp",5+power);
                                message_vision("$N�V�O���Q��$n���ꥴ�}�A���O���ѤF�C\n",me,obj);
                                obj->pick_lock_fail(me,arg); //�i�H�����Ѫ��N��
                                me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
                                return 1;
                        }
                } else return notify_fail("���ӪF��S����k���A�}��C\n");
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
                if( !dir ) return notify_fail("�o�Ӥ�V�S�����C\n");
                //key=env->query_door(dir,"key");
                //if(!key ) return notify_fail("�o�Ӫ��èS���W��!\n");
                        
                if( doors[dir]["status"] == DOOR_SMASHED )
                        return notify_fail("�o��" + doors[dir]["name"] + "�w�g�a�F�C\n");
                if( doors[dir]["status"] == DOOR_OPENED  )
                        return notify_fail( doors[dir]["name"] + "�w�g�O�}�۪��F�C\n");
                if( !(doors[dir]["status"] == DOOR_LOCKED)  ) 
                        return notify_fail(doors[dir]["name"] + "�èS���W��C\n");
                if( env->query("no_pick") ) return notify_fail(doors[dir]["name"] + "����O�S�s���A���|�}�C\n");
                i=env->query("pick_level");
                power=1+random(40+me->query_skill("pick_lock"))-i;
                if(power >= 30)
                {
                        if(env->unlock_door(dir))
                        {
                                me->receive_damage("mp",5+power/8);
                                message_vision("�y..��.��!!.�z"+"$N���\\���N" + doors[dir]["name"] + "���ꥴ�}�F�C\n", me);
                                                                me->improve_skill("pick_lock",5+random(20)+random(me->query_int()/2));
                                return 1;
                        }
                        
                }else
                {
                                me->receive_damage("mp",5+power/8);
                                message_vision("$N�V�O���Q��" + doors[dir]["name"] + "���ꥴ�}�A���O���ѤF�C\n",me);
                                env->pick_lock_fail(me,dir); //�i�H�����Ѫ��N��
                                me->improve_skill("pick_lock",3+random(10)+random(me->query_int()/3));
                                return 1;
                }
        } else return notify_fail("�o�̨S�����C\n");
        return 0;
}
 

