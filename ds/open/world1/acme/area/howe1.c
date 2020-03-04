inherit ROOM;
void create()
{
        set("short", "�}��");
        set("long", @LONG
���a���򤧫e�����P�I�M���P�A�o�̤Q���e���A�S������F�A���b��
�����a��o���@�ӨF��A�|�P���t�����A�A�J�Ӫ��ݤF�ݥ|�P�A�o�{
�b�A���e���Ӥ��A�����w��a�o����X�o�Ӳ`�ޡC
LONG
        );
set("exits", ([ /* sizeof() == 2 */
   "north" : __DIR__"howe",
]));
set("objects",([
__DIR__"npc/worm" : 3,
]) );
    set("no_clean_up", 0);
    set("item_desc", ([
        "���" : "�o�Ӥ��۷���¡A�ϥ�(use)�����ӭn�p�ߡC\n",
        "�F��" : "�A�n�_���ݤF�ݳo��F�A�������Y����F��C\n",
        "�Ͱ�" : "�A�J���@�F�@�o��Ͱ��A�o�{�L���ǩ�ۤ@�U�Ȩ�A�o�K�K�K�K\n",
    ]));
        setup();
}
void init()
{
    add_action("do_search","search");
    add_action("do_use","use");
}
int do_use(string arg)
{
       object me;
       me=this_player();
       if(arg != "���") return 0;
       else {
         message_vision("$N�N���[�b�𨤡A�p���l�l�����W���C\n\n",me);
         me->move(__DIR__"hills2");
         return 1;
       }
}
int do_search(string arg)
{
   object me;
   me=this_player();
   if(arg != "�F��") 
   {
     if(arg != "�Ͱ�") return 0;
     else {
       if(query_temp("getsilver")) return notify_fail("�A�j�d�F�Ͱ��A���oı�õL�S�O���B�C\n");
       else {
        message_vision("$N�q�o��Ͱ��W�j�X�@�ǻȨ�C\n",me);
        me->receive_money(2000);
        set_temp("getsilver",1);
        set("item_desc", ([
        "���" : "�o�Ӥ��۷���¡A�ϥ�(use)�����ӭn�p�ߡC\n",
        "�F��" : "�A�n�_���ݤF�ݳo��F�A�������Y����F��C\n",
        "�Ͱ�" : "�A�J���@�F�@�o��Ͱ��A�èS������S�O���B�C\n",
        ]));
        call_out("delay",600,this_object());
       }
     }
return 1;
   }
   else {
        message_vision("$N�J�Ӫ��j�d�ۨF��A���M�o�{���Y���@��Ͱ��C\n",me);
        return 1;
   }
}
void delay(object room)
{
    delete_temp("getsilver");
    set("item_desc", ([
        "���" : "�o�Ӥ��۷���¡A�ϥ�(use)�����ӭn�p�ߡC\n",
        "�F��" : "�A�n�_���ݤF�ݳo��F�A�������Y����F��C\n",
        "�Ͱ�" : "�A�J���@�F�@�o��Ͱ��A�o�{�L���ǩ�ۤ@�U�Ȩ�A�o�K�K�K�K\n",
    ]));
}
