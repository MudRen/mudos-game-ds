#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�կ���",({"egg powder","powder"}) );
        set("long",@long
�o�O�@��Ѱ���J�ҿi�ƪ������A���դ��������a�ۤ@�Ѵc��A�W�C
�ѤU�����ʦW���C�A���֪Z�L���H�����A�u�n��o�د�����١]daub�^�b
�Z���W�Y�A�|���ɸӪZ�����\��A���@���i�h�o���_���C
long
);
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1000);
        set("unit","��");
        }
        setup();
}

void init()
{
        add_action("do_daub","daub");
}

int do_daub(string arg)
{
        object wp,me,ob;
        int roll;
        me=this_player();
        ob=this_object();

        if(!arg ) return 
                notify_fail("�A�n��կ�����٦b���˪Z���W�H�H\n");
        if(!objectp(wp=present(arg,me) ) )
                return notify_fail("�A���W�S���o�˪F��C\n");
        if(!wp->query("skill_type") )
                return notify_fail("�o�˪F�褣�O�Z�����C\n");
        if( wp->query("equipped") )
                return notify_fail("�A��������U�o�ӪZ���C\n");

        if( wp->query_temp("egg_daub") >= 10) {

                tell_object(me,"�ݼˤl�A"+wp->query("name")+NOR "�w�g����A��կ����F�C\n");
                return 1;
        }

        message_vision("$N��@��կ������æa��٦b$n"+NOR "���C\n",me,wp);    
        roll = random(100);
        if( roll < 50 ) {
                string attr, c_attr;
                attr = "armor";
                c_attr = "���m�O";
                if( roll < 2 )        { attr = "str"; c_attr = "�O�q"; }
                else if( roll < 6 )  { attr = "con"; c_attr = "���"; }
                else if( roll < 8 )  { attr = "int"; c_attr = "���z"; }
                else if( roll < 18 )  { attr = "dex"; c_attr = "�ӱ�"; }
                else if( roll < 30 ) { attr = "hit"; c_attr = "�R���v"; }
                wp->add( "weapon_prop/"+attr,1);
                tell_object(me, HIY "�Aı�o"+wp->query("name")+HIY"��"+ c_attr +"�ȴ����F�T\n" NOR);
                wp->add_temp("egg_daub", 1);         //��L����
        }
        else tell_object(me,"�A�èS��ı�o"+wp->query("name")+NOR "�M���e���󤣦P�C\n");
        destruct(ob);

        return 1;
}


