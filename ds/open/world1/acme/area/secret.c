inherit ROOM;
void create()
{
        set("short", "�K��");
         set("light",1);
        set("long", @LONG
�o�̬O�@���p�K�ǡA���a�ɬO�Фg�A�|���g��鸨�p�ɡA���e���@�i
�ۻs�p��A�p��ǧ��ۤ@���e���A�e�����Y�`�e�{�ۤ@�Ѷ®�A��M�O��
�����r�Ӥ`�A�K�Ǫ��F�䦳�ӥX�f�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tnb",
]));
        set("no_clean_up", 0);
      set("item_desc", ([
        "�p��" : "�o�ӥۻs�p��۷����¡A��W���i�ȡC\n",
        "�e��"  : "�o���e���Y�W�}�F�Ӥj�}�A�i�������H�̤O�j�L�a�C\n",
        "��"  : "�o�i�Ȥw�x���A�W�Y�g�F�X��r�A�A�i�H���_��(take)�ݡC\n",
      ]));
      setup();
}
void init()
{
    add_action("do_search","search");    
    add_action("do_take","take");
}
int do_search(string arg)
{
     object me;
     object peachsword;
     me=this_player();
     if(query_temp("getsword"))return notify_fail("�A�F½���A���O�o�S��줰��C\n");
     if(arg != "�e��") 
     {
      return 0;
     }
     else {
     message_vision("$N�J���@�F�@�e���A�o�{�e������W���ۤ@��C�A�C���ձ��b�a�W�C     \n\n",me);
        peachsword=new(__DIR__"npc/wp/peachsword.c");
        peachsword->move(__DIR__"secret.c");
        set_temp("getsword",1);
        call_out("delay",600,this_object());
        return 1;
        }
}
int do_take(string arg)
{
    object me;
    object paper;
    me=this_player();
        if(query_temp("getpaper"))return notify_fail("����H\n");
     if(arg != "��") 
     {  
      return 0;
     }
     else {
     message_vision("$N�q��W���_�ȡC\n\n",me);
     paper=new(__DIR__"obj/paper.c");
     paper->move(me);
     set_temp("getpaper",1);
     set("item_desc", ([
        "�p��" : "�o�ӥۻs�p��۷����¡A����W�o�ŵL�@���C\n",
        "�e��"  : "�o���e���Y�W�}�F�Ӥj�}�A�i�������H�̤O�j�L�a�C\n",
      ]));
        call_out("delay",600,this_object());
        return 1;
        }
}

void delay(object room)
{
      delete_temp("getsword");
      delete_temp("getpaper");
      set("item_desc", ([
        "�p��" : "�o�ӥۻs�p��۷����¡A��W���i�ȡC\n",
        "�e��"  : "�o���e���Y�W�}�F�Ӥj�}�A�i�������H�̤O�j�L�a�C\n",
        "��"  : "�o�i�Ȥw�x���A�W�Y�g�F�X��r�A�A�i�H���_��(take)�ݡC\n",
      ]));
      set("light",1);
}
