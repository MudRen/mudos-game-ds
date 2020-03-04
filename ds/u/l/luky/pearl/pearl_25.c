// Room: /u/l/luky/room/pearl_25.c
inherit ROOM;
void create()
{
set("short", "[1;32m�ڪB�V�׹D�|[m");
set("long", @LONG

     �o�ӭ׹D�|�O�Ѥj��̼ڪB�V�ҳЫءA�b 7�~�e�P���w�������@
 ���j�ԫ�A�ڪB�V�M�L���Ԥ̫ͭK�����h�V�C�L���̤l���~�ӤF�L��
 �N�ӡA���ԾĪ��M��t�N�A�H������A�ת��d���C

                        ��  
                          ��  
                       _�[_.O. 
                      /\__.\/ �� 
                      \/__\  
                       | :|              k
                       | :|           O  |
                     �g�i�i�g       ()Y==o
               �i�g�i�i�J���i�i�g�i  /_\ |
               �i�i�i�i�i�i�i�i�i�i  _W_ |
   �áááááááááááááááááááááá�

LONG
);
set("objects",([
__DIR__"npc/chufighter":2,
]));
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_37",
"leave" : __DIR__"pearl_23",
]));
set("item_desc",([ //����
  "statue":"�o�O�j��̼ڪB�V���J���C\n",
  "�J��":"�o�O�j��̼ڪB�V���J���C\n",
  "words":"�A�i�H�յ�ŪŪ��(read words)�C\n",
  "�j��":"�A�i�H�յ�ŪŪ��(read words)�C\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
 object me;
 me = this_player();
 if( !arg || (arg != "words"))return notify_fail("�A�nŪ����?\n");
 if(random((int)me->query("int"))<20)
   message_vision("$N�ݤF�b�Ѥ]�ݤ��X�O����N��C\n",me);
 else
 {
  message_vision("$N�ݤF�@�U�A�o�{�W���g��[�}�o��]�C\n",me);
  me->set_temp("statusword",1);
 }
 return 1;
}
