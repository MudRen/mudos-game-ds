#define WALLDATA        "/u/l/lestia/log1/post.txt"
#include <ansi.h>
inherit ROOM;
string base_long;
void load_wall_data();
void create() {

     set("short", HIC"�d����"NOR);

        base_long = @LONG



         
�A�npost ����?



---------------------------------------------------
LONG;
        set("long", base_long);
        set("exits", ([
   "down" : "/u/l/lestia/workroom",
        ]));

        setup();
        load_wall_data();
}
void init()
{
write (HIW+"\n
�١�"+HIB+this_player()->query("name") +HIC+"--"+HIY+"�����D�i�H�d�U�ӳ�(post xxx)��I\n\n \n"+NOR);
   add_action("to_post","post");
}
int to_post(string arg) {

        object usr;

        usr = this_player();
  if(!userp(usr) )
                return notify_fail("�D���a���⤣��d���C\n");
if(usr->query_temp("invis")) return notify_fail("���Τ���d���C\n");


        if(arg) {
 write_file(WALLDATA, usr->query("name")+"("+ usr->query("id") +"):" + arg + "\n");
                message_vision("$N�@�����_���g�g�g�A�ש��d���g�W�F�C\n", usr);
                tell_object(usr, "��ߧa! �z���d���|�ܧ֪����бz��!\n");
                load_wall_data();
                return 1;
        }
        else
                return notify_fail("�z�n�d����d��?\n");


}

void load_wall_data() {

        string appendlong;

        if(file_size(WALLDATA) == -1) {
                appendlong = "\n    �ȮɨS�����󪺢��������C";
        }
        else {
                appendlong = "\n    �H�U�O�C�ӤH�b�o�̩үd����������:\n\n" + read_file(WALLDATA);
        }

        set("long", base_long + appendlong + "\n");

}


