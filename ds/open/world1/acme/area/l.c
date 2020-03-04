inherit ROOM;

void create()
{
        set("short", "�y�i��");
        set("long", @LONG
�o�̬O���@�B�T�ƤV�����ѵM�r���U�A�ˤ��ۤW�ӭ��A�g�J��e��
�O�դ��`���A�S���_����A�b��e�@���j�۲��u���A���Q�W�ӡA���X��
��Q�V�A�����_�[�C�b�A���e���@�ѵM�����ƥ��ۡA�۪��p��A��j���K
�P�઺�⭿�l�A�|�ǦC����ԭ�A�ۦb�����A������Ψðt�H�[�y�A�Z�D��
�u���򧮦������I
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"l2",
  "down" : __DIR__"valley",
]));
  set("item_desc", ([ /* sizeof() == 1 */
    "����" : "�o�����ۦ��G���O�ѵM�ͦ��A�O�D�D�a�a���H���A�����X�ʦ~�F\n"
             "����ɪZ�L���L�u�ۤV�H�v�A�H�L�ۯ��\\�d�ΦӦ��I�ۮ�ۼ[�b\n"
             "��᤭�V�A�o�����ۡA�U�H�����_�F�ӦW�r�s�u�x�s�W�v�C\n",
    "�x�s�W" : "�A���Y���x�s�W�W�Y�ݥh�A�ߤ��@�ʡA�u���F��ѻڡA�椧��\n"
               "�b���y�i��W��A�����εM�p���ΤW�U���ʡA���Τ@�ɦʤV�A\n"
               "���������A�����ˤɤW�U�A�p���W�U���w�A�Y���\\�y�ڻᰪ�A\n"
               "�γ\\��W�D(jump)�@�[\n",
  ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{ 
         add_action("do_swim", "go");
         add_action("do_jump","jump");
}
int do_jump(string arg)
{
          object me;
          me=this_player();
          if(arg != "�x�s�W") return 0;
          if(me->query_skill("dodge")<60) return notify_fail("�A�����\\�y�ڤ����A�O�D���W�h���C\n");
          else {
            message_vision("$N�ϥX���V�����\\�A���x�s�W�D�h�C\n",me);
            me->move(__DIR__"dragon");
            return 1;
          }
}
int do_swim(string arg)
{
        object me;
        me=this_player();
        if( (arg!= "down") || !this_player()->visible(this_object()) ) return 0;
        if(me->query_skill("swim") < 30)
        {
          tell_object(me,"�A���a�ޤ����¼��A��J�����N�|���ͩR�M�I�C\n");
        }
        else {
          message_vision("$N�`�`���l�F�@�f��A��J�u�y�i��v�F�C\n",me);
          me->move(__DIR__"valley");
        }
        return 1;
}

