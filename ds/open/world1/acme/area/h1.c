inherit ROOM;

void create()
{
        set("short", "�۫�");
        set("light",0);
        set("long", @LONG
�A�@�}��i�o�̡A�Kı�Ʊ������A�u�Pı�o�̳��˴˪��A��M�@��
���N�������A�y�W�j�h�A�A���T���F���G�ۡA�b�𨤧A�i�H�ݨ�@�Ѵ�
��A���e��]���G�Ѵä�A�A�u�O�Q�֧����}�o��................�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"pathway7",
        ]));
        set("no_clean_up", 0);

     set("item_desc", ([
         "�ä�" : "�o�ä�ݰ_�Ӭ۷���¡A�A���G�i�H�ȶ}(uncover)���C\n",
     ]) );
        setup();
}
void init()
{
        add_action("do_uncover","uncover");
}
int do_uncover(string arg)
{
        object me;
        object zombie;
            object zombie2;
        me=this_player();
        if(query_temp("kkzombie")) return notify_fail("����H\n");
        if(arg != "�ä�" ) 
        {  
          notify_fail("�A�n�ȶ}����H\n");
          return 0;
        } 
        else { 
          message_vision(
          "$N�N�e�����ä쥴�}�A��M�q�ä�̸��X�F�G���L��....\n\n"
         "�Ať���L�ͧC�n�R�q�F�X�n.....\n"
         "��M�A�P�򪺴ä쳣���X�F�L��.....\n"
         "�A��Mť���ä�̤@�n�u�F���v���T�A��Ӵé��򳴤F�C\n"
         ,me);
        
        zombie=new(__DIR__"npc/zombie.c");
            zombie2=new(__DIR__"npc/zombie.c");
        zombie->move(__DIR__"h1");
              zombie2->move(__DIR__"h1");
        set("exits", ([
          "north" : __DIR__"pathway7",
          "down" : __DIR__"tnb",
        ]));
        set_temp("kkzombie",1);
        set("item_desc", ([
        "�ä�" : "�o�ä���G�w�g�Q�H���}�F�C\n",
        ]) );
set("long", @LONG
�A�@�}��i�o�̡A�Kı�Ʊ������A�u�Pı�o�̳��˴˪��A��M�@��
���N�������A�y�W�j�h�A�A���T���F���G�ۡA�b��}�A�i�H�ݨ�@�Ѵ�
�A���e��]���G�Ѵä�A���O�w�g�Q�H���}�F�C
LONG
);
        return 1;
   }
}
