#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name(YEL"����"NOR,({"cecily"}));
       set("long",@LONG
    �@�ӤQ�����R���k�l�����b�o�̡A�`�㪺�������t���o�z�����~�A��
�������B�D���ۦo����j�C���ۤ@�Y�W���������u�v�A�ֲӪ����߲@���S
�ݦa�����۰ӷ|���j�j�p�p���ưȡA�o�O�ӤH�������f�f�A�]�O�ĺ��Ĵ�
�ۦW�����H�C���L���M�o�U�譱���Q�����n�A���O��k�H�Ө��o�o���@��
�Q�����j�����I�w�o�u���w�k�H�C
LONG);
       set("gender","�k��");
       set("age", 23);
       set("level", 15);
       set("chat_chance", 3);
       set("chat_msg", ({
            "�����W���������۹٭p�̷h�B�ӫ~�C\n",
            "�����b�o��W�����l�W�O�U�@�ǪF��C\n",
            "�������F���Y�W�����A�S�F�@�j�f��A�S�~�򦣸L�F�C\n"
           }));
       set("talk_reply",".....(�������ۤ@�ӹ٭p�A�ݨӬO�s�A���ƴN�h��٭p�ͧa�I)\n");
       set("storeroom",__DIR__"obj/shop");
       set("no_fight",1);
       setup();
       carry_object( __DIR__"eq/dress")->wear();         

}
void init()
{         
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
          add_action("do_buy","buy");
          add_action("do_sell","sell");
          add_action("do_list","list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( ob->query("gender") ) {
           case "�k��":
               say("�����i�i�ݤF"+ob->query("name")+"�@���A�ĤF�f��A�S�^�L�Y���ۤv���ƤF�C\n");
               break;
           case "�k��":
               if(ob->query("age")>30)
               {
                 say("�����i�i�ݤF"+ob->query("name")+"�@���A�ĤF�f��A�S�^�L�Y���ۤv���ƤF�C\n");
                }
                else{
                 say("���������@�G�I�n��"+ob->query("name")+"�ݤF�n�@�|��C\n");
                 command("blush");
                }
               break;
           default:    
                say("������L�Y�A�n�_���n��" + ob->query("name") +"���ݥk�ݡC\n");
                break;
        }
}

