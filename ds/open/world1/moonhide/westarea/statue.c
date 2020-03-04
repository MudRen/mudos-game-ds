#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me,object ob);

void create()
{
        set_name(HIY"������"NOR ,({"golden bell","bell"}) );
        set_weight(5000000); 
        set("long", @long
�������O�Ůq�W�S��������A�ӳo�y�������A�ڻ��O�|�ʦ~�e����
��j�a�ɤW�Ӫ��C�������e�\���B�������֡A�̭������a���O�N�L�����u
�A�γ\�A�i�H�ոզb�o���ָ̿N(fire)�@�ǪF��C
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�y");
                set("no_get",1);
                set("no_sac",1);
                set("value", 1);
        }
        setup();
}

void init()
{
        add_action("do_firing","fire");
}

string WAR_FILE = "/open/war/soul_war.c";
int do_firing(string arg)
{
        object me,ob,torch;
        me=this_player();
        ob=this_object();
        if( WAR_D->isActive(WAR_FILE))
                return notify_fail("�u�Ůq���ԡv�٨S�������C\n");
        if(!objectp(torch=present("torch",me) ) )
                return notify_fail("�A���W�S������C\n");
          if(!arg || arg!="����")
                return notify_fail("�A�n�I�U����F��?\n");
        message_vision(HIW"$N���_"HIR"����"HIW"�I�U�F���ָ̪��F��C\n"NOR,me);
        destruct(torch);
        call_out("open_war",3,me,ob);
        return 1;
}

void open_war(object me,object ob)
{
        message_vision(HIM"�U�N�����֫_�X�����Q���A���O���}�F�Y�ӳq�D...\n"NOR,me);
        
        if( !WAR_D->doStartWar(me, WAR_FILE) ) {
                        tell_room(ob, "���O����Ƥ]�S���o�͡C\n");
        }
}


