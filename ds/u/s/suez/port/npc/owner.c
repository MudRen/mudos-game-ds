inherit NPC;
inherit SELLMAN;
void create()
{
       set_name("�s������",({"owner"}));
       set("long",@LONG
    �o�Ӥ��~�k�l�O�u�W���H���C��v������A�L���ӬO�@�W����A�H��
�Ө��ĺ��Ĵ��䪺�ɭԡA�o�{�o�̳��M�S���s���I�L�@�𤧤U�N�b�o�̶}
�F�Ĥ@�a�s���C�L���Ӥ��⪺�өʤ��M�S��A���n���@���]�l�ޤF�ܦh�_
�I�̡A�o�]�ϱo�L�����`�O�R���F�H�H�ί��n�C
LONG
);
       set("gender","�k��");
       set("age", 45);
       set("level", 20);
       set("attitude", "peaceful");
       
       set("sell_list",([       
           __DIR__"obj/beer"  : 25, 
           __DIR__"obj/fish"  : 25
       ]) );                                 
        set("talk_reply","�ڬO�S����ưաI���O��Ȥ��Ҫ��S����G�b�дo�ۤ���C\n");   
        setup();
        
}
void init()
{       
        add_action("do_list","list");
        add_action("do_buy","buy");
}

