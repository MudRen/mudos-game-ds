// Room: /u/a/acme/area2/t30.c

inherit ROOM;

void create()
{
        set("short","�խߦa��[�a�U�T�h]");
	set("long", @LONG
�o�̬O�խߦa�����a�U�T�h�A�|�P���t�����A�����~�~�A�A���T���F�ӴH
Ÿ�A�����o�X�u�ء�ء��v�������n�T�A�b�A���e������ݨ������k�G�ƪ�
�j�۬W�A�۬W�򦨤@�Ӷ��A�b�۬W�����o�����J���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"t29",
]));
  set("item_desc", ([ /* sizeof() == 1 */
"�J��" : "�o�O�@�L�ᬰ�ǲ����J���A���}�}�}�e���B���A���y�W���o�ᬰ�ᮺ�A�u�Q���L[���|��]�C\n",
  ]) );
	set("no_clean_up", 0);

	setup();
}
void init()
{ 
         add_action("do_aruba","aruba");
}
int do_aruba(string arg)
{
          object me;
          me=this_player();
          if(arg != "�J��")
            return 0;
          else {
            message_vision("$N�ĹL�h���J���[��!!�����۬W��h�A�uť���J���G�I�@�n�A�����H���A�w���F�g�C\n\n",me);
            message_vision("$N�]��o�Өϫl�A�@�ɰ�����A�@�Y���۬W���h�A�۬W���n�ӭˡA�X�{�F�ӥX�f�C\n",me);
message_vision("$N�]�Y������j�P�������A�Y�}�F�Ӥj�}�A�A�夣�����y�X�A$N�Y������A�n�n���Y�C\n",me);
            set("exits",([
               "north" : __DIR__"t29",
               "southdown" : __DIR__"t31",
            ]) );
            me->receive_wound("head",10);
            return 1;
          }
}
int valid_leave(object me, string dir)
{
       if( dir=="southdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
        return ::valid_leave(me, dir);
}
