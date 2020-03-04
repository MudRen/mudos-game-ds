#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ݪ���", ({"watchdog","dog"}) );
        set("long", "�@�����߯կժ��ݪ����A�}���O�@�J�f�E\n");
        set("unit","��");
        set("race", "���~");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}" })); //���𳡦�
        set("verbs", ({ "bite","poke","crash" })); //�������A��hoof��crash�rbite��claw��poke
        set("age", 5);
        set("level",20);
        set("dex",50);
        set("str",50);
        set("con",50);
        set_temp("apply/hit",20);      
        set_temp("apply/dodge",20);    
        set("max_hp",3000);
        set("evil",-10);
        setup();
}

void init()
{
    object me=this_player(),obj;
    add_action("do_throw","throw");

    if(objectp(obj=present("dump",me))){
    command("drool "+me->query("id"));
    tell_object(me,"���e�o���ݪ������ڤڪ���ۧA�⤤���ץ]�A�L���٤@�����y�f���C\n"); 
    tell_object(me,HIW"(�γ\\��]�l��(throw)�X�h�A���o�������޶}�C)\n"NOR); 
    }
}

int do_throw()
{
    object me=this_player(),obj,ob=this_object();
    
    if(objectp(obj=present("dump",me))){
    message_vision(HIY"$N�ǥX�h����$n�������@��A$n�����b�������ѪŤ��C\n"NOR,me,obj);
    message_vision(CYN"$N�L���@�n�A�µ�$n�]�h�A�]�����b�������ѪŤ��C\n"NOR,ob,obj); 
    destruct(obj);
destruct(ob);
    }
    return 1;
}
    
    
