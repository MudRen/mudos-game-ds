// 2001.7.25 version
// �s�Whorse->setting(id) �H�ѧO���D����
// �]�w���C�H�u���R�@�ǰ�
// alickyuen@ds 2003.1.12
#include <dbase.h>
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�P�Գs", ({ "horse seller" , "seller" }) );
        set("long", @LONG

�b�B�F�����s�԰��\���D�H�A�L���Τߪ����U�U���������Ǥ��C
�A�i�H�ݰݥL���樺�ذ�(list)�A�άO�V�L�ʶR�U�ث~�ت���(buy)�C
    
LONG
        );
        set("level", 10);
        set("no_fight",1);
        set("age",   50);
        set("chat_chance", 1);
        set("chat_msg", ({
  (: command("say �̪�u�O���r..") :),
  (: command("sigh") :),
  (: command("say �����D�ٷ|���ȤH�W���_ ?") :),
}) );
        set("sell_list",([      
                    "/open/world1/horse/horse1": 5,
                    "/open/world1/horse/horse2": 5,
                    "/open/world1/horse/horse3": 5,

]));
        setup();
        add_money("coin",50);
}

void init()
{
     ::init();
        add_action("do_buy","buy");
        add_action("do_list","list");
}
