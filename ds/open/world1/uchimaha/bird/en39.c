inherit ROOM;
void create()
{
set("short","�F�_�A�L");
set("long", @LONG
�A�ש󨫥X�F�h�A��, �A�Pı��U�������B, �o�̦�
�ǰ��j�����M�ᦷ, �A�ݨ��W���@�Ӧp�Y�`��j����
�_, �����٦��Ǫ��Y���b�r��.
LONG
        );
        set("exits",(["south":__DIR__"en38",
                      "northwest":__DIR__"en40",
               ]));
        
        set("item_desc",([
        "���_":"�o�O�@�Ӧ��Y�`��j�����_�A�p�G�A�߱����n�A�A�i�H�ΤO�𥦨�}(kickkick)�C\n",
         ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{ 
         add_action("do_kickkick","kickkick");
}
int do_kickkick(string arg)
{
          object me;
          me=this_player();
          if(arg != "���_")
            return 0;
          else {
            message_vision("$N��M�߱��ܤ��n�A�Q�h����_��}�C\n\n",me);
            message_vision("$N�ΤO�������_�W��F�U�h�A������_���F�U�ӡA�e�������������q���_�̴�X�C\n",me);
            message_vision("�@�j�s�e����$N�����W���W�A�h��$N�z�z�j�s�A�y�ɹM����ˡC\n",me);
            me->receive_wound("head",2);
            me->receive_wound("body",2);
            me->receive_wound("left_leg",2);
            me->receive_wound("right_leg",2);
            me->receive_wound("left_arm",2);
            me->receive_wound("right_arm",2);
            return 1;
          }
}

