inherit ROOM;
void create()
{
        set("short", "�y�����s��");        
        set("long",@LONG
�A�Ө�y�������s���A�ݨӦ����֤H�b���a�A�ݥL�̪������n���O
�b�Q�פ���ơA�_��O�q�����|�Y�خa�A�y���������|�Y��ť���O���L
���H���I�A�ӪF��O���y�������a�A���n��O�@�ǥ��v�A�]�\���|��
�����s���۰��H�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"po11",
  "west" : __DIR__"po9" ,  
  "east" : __DIR__"po16",
  "south" : __DIR__"po13",
]));
      set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/villager" : 4,
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}







