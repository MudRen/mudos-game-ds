#include <ansi.h>

inherit NPC;

void create()
{
        
        set_name(HIR"���K"HIG"���s"NOR,({"Flame of Dragon","dragon"}) );
        set("race", "���~");
        set("level",100);
        set("age",1000);
        set("long", "�@�������л\�л\�����s���b�o�̡C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"}));
        set("verbs", ({"bite"}));
        set("bullet",5000);
        set("count",5000);
        set("value",1000000);
        set("ridable",1);              
        setup();
}

void init()
{
	add_action("do_order","order");
        add_action("do_fly","fly");
        add_action("do_fire","fire");
}

int do_fly(string arg) 
{
        object who,me;
        int count1;


        if( this_object() != present(this_object(),this_player()) )
                return notify_fail("�A�å��M�W���s�C\n");

        if( !arg ) return notify_fail("�A�Q���쩹����?\n");

        me=this_player();
        who = find_player(arg);
        if (!who) who = find_living(arg);
        if (!who) return notify_fail("�A�Q���쩹����?\n");

        count1 = (int)this_object()->query("count");
        if( (count1 -= 4) < 0 ) {
                count1 += 4;
                set("count",count1);
                return notify_fail(this_object()->name()+"�w�g�����O�q�H�i�歸��C\n");
        }

        set("count",count1);
                message_vision("$N"HIW"���s���l��ʡA�µ۲��I�����C\n"NOR,this_object());
        tell_room(who,this_object()->name()+HIB"���즹�a�A�w�C�a�U����a���C\n"NOR);
        me->move(environment(who));
        return 1;
}
int ride_before_action(object me)     
{
        int s = me->query("str");
        if( s<90 || !s )
        {
                message_vision("�ѩ�$N���O�q�����A�L�k����"+this_object()->name()+"�A�]�ӳQ"+this_object()->name()+"�q���s�I�W�L�F�U�ӡI\n",me);
                return 0;              
        }
        else
        {
                message_vision("$N�ϥX�������Z�O�ǳƩ��A�o��"+this_object()->name()+"�C\n",me);
                return 1;              
        }
}

int ride_after_action(object me)       
{
        message_vision("$N�w�g�M�W�F"+this_object()->name()+"�C\n",me);
        return 1;                      
}


int ride_off_action(object me)   
{
        message_vision("$N�w�g���}"+this_object()->name()+"�F�C\n",me);
        return 1;                     



}
int do_fire(string act)
{
        string msg;
        object ob,target;

        ob = this_object();
        if( this_object() != present(this_object(),this_player()) )
                return notify_fail("�A�å��M�W���s�C\n");

        if(ob->query("bullet")<=0) {
                write(this_object()->name()+"���u��w�g�ӺɡC\n");
                return 1;
        }

        if( act ) target = present( act, environment(this_player()) );

        if(!target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==this_player() )
                return notify_fail("�Ы��w�����ؼСC\n");

        msg = "$n"+HIR+"�C�C���i�}��L�j�f�C\n"NOR;
        message_vision(msg,target,ob);
        message_vision("$n"HIB"�O�|�P��Ŷ}�l�W�ɡC\n"NOR,target,ob);

        call_out("fire_2",5,this_player(),target,ob,act);
        this_player()->start_busy(3);
        return 1;
}

int fire_2(object me,object target,object ob,string act)
{
        string msg;
        int damage,i,bul,dp,pp,dx,nt,kr,cha;

        pp = COMBAT_D->skill_power(target, "parry");// SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge");
        dx = target->query_dex();
        nt = target->query_int();

        cha = pp*2 +dp*2 +dx +nt +target->query_armor()*3;

        for(i=0; i<10; i++)
        {
                bul = (int)this_object()->query("bullet");
                if ( (bul -= 50+random(100) ) < 0 ) {
                        bul += 50+random(100);
                        set("bullet",bul);
                }  
                set("bullet",bul);

                damage = 500+random(500) -cha/3;

                if(ob->query("bullet") <= 0 ) 
                {
                        message_vision("$n"HIW"���u��w�g�ӺɡA�ҥH����Q�X���K�C\n"NOR,target,ob);
                        ob->set("bullet",0);
                        break;
                }
                else{
                        msg = HIY"�q�f���Q�X��"+(i+1)+"�i�����K��"NOR;
                }
                if ( damage > 0) {
                msg +=HIR"$N"HIR"�A��g�Q�ӥX�C"HIR"(" + damage + ")\n" NOR;
                        message_vision(msg,target,ob);
                        target->receive_damage("hp", damage, me);       
                        COMBAT_D->report_status(target);                
                }  else {
                msg +=HIW"�i�O���K�L�`���I�N�b"NOR"$N"HIW"���W�C\n"NOR;
                message_vision(msg,target,ob);
                } 
        }
        me->start_busy(1);
        target->start_busy(1);
        return 1;
}
int do_order(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="sonicct")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rorder <�Y����> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");
        command(cmd);
        return 1;
}