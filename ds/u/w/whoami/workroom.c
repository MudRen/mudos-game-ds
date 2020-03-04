inherit ROOM;
#include <ansi.h>
void create()
{
  set("light",1);
  set("long", HIC"\n�g���� ���e�����ѤW�ӡ@�b�y������_�^\n" 
              "�g���� �������d�վv  �¦p�C���Ǧ���\n" 
              NOR+CYN"       �H�ͱo�N�����w  ���Ϫ���Ź��\n"
              "       �ѥͧڧ�������  �d�������ٴ_��\n" 
              "       �i�Ϯ_���B����  �|���@���T�ʪM\n" 
              HIW+BLK"       �¤Ҥl  ���C��  �N�i�s  �g����\n" 
              "       �P�g�q�@��      �Чg���ڰ���ť\n" 
              "       �����W�ɤ����Q  ���@���K���@��\n" 
              "       �j�Ӹt��ұI��  �������̯d��W\n" 
              HIR"       �������ɮb����  ��s�Q�d���N�\n" 
              "       �D�H�󬰨��ֿ�  �|���f����g�u\n" 
              "       ���ᰨ  �d����  �I��N�X�����s\n" 
              "       �P���P���U�j�T\n"  
              "                     \n\t\t"NOR"       ����"HIW"�m"HIY"�N�i�s"HIW"�n\n"NOR);
    set("short",HIY"WorkRoom"NOR);
    set("exits",([
]));
    set("objects", ([ 
]));
        set("valid_startroom", 1);
  setup();
        call_other("/obj/board/whoami_b", "???");
}

void init()
{
     add_action("do_wizlist","wizlist");
     add_action("do_link","link");
     add_action("do_dellink","delink");  
     add_action("do_reboot","reboot");
}

int do_wizlist(string str)
{
    int i,n;
    object *user,room;
    user = users();
    n=sizeof(user);

message_vision(HIC"�u�W�Ův�@����\n"NOR,this_player());
message_vision(HIW"==============\n"NOR,this_player());
for(i=n-1;i>=0;i--)
{
 room = environment(user[i]);
 if(wizardp(user[i]))
       {
        message_vision(RANK_D->query_rank(user[i])+user[i]->name()+"("+user[i]->query("id")+")�{�b�b"+room->query("short")+"��\n",this_player());
       }
}
return 1;
}
 
int do_link(string arg)
{
    object me;
    me = this_player();

    if(!arg)
    return notify_fail("�A�n�s���֪��ж��C\n");
   if(file_size("/u/"+arg[0..0]+"/"+arg+"/workroom.c") <= 0)
    return notify_fail("�S��"+arg+"���u�@�ǡC\n");
   if(__DIR__"workroom.c"->query("exits/"+arg))
    return notify_fail("�A�w�g���q��"+arg+"�u�@�Ǫ��J�f�F�C\n");
   __DIR__"workroom.c"->add("exits", ([arg :  "/u/"+arg[0..0]+"/"+arg + "/workroom.c"]));
    message_vision(HIC"$N�W�[�F�q��"+arg+"�u�@�Ǫ��J�f�C\n"NOR,me);
    return 1;
}

int do_dellink(string arg)
{
    object me;
    me = this_player(); 

    if(!arg)
    return notify_fail("�A�n�R����ֳs�����ж��C\n");
}
