// Room /u/l/luky/room/lukyroom1
#include <ansi.h>  //�Y�n�Φ��C�⪺���[����
#include <room.h>  //�n�[���n�o�@��
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
set("short",HIG"�s���c�ޤ���"NOR);
set("long",
HIC"\n                  �b�c�d�e�f�g�h�i�i�h�g�f�e�d�c�b
"HIB"                  �i�i�i�i�i�i"HIY"�s���O��"HIB"�i�i�i�i�i�i             "HIG"����
"HIB"                   �m         "HIR"��������"HIB"          �m"HIG"   ����     ���i��
"HIC"     �b�d�e�f�g�h�i"HIB"�m "HIR"������  ��������  ������"HIB"  �m"HIG"  ���i��   ���i�i��
"HIB"      �m           �m"HIR" ������  ��    ��  ������"HIB"  �m"HIG" ���i�i�� ���i�i�i��
"NOR+YEL"������������������"HIB" �m"HIR" ������  ��  ����  ������"HIB"  �m"HIG"���i�i�i���i�i�i�i�i��
"NOR+YEL"������������������"HIB" �m"HIR"         ��    ��"HIB"          �m"HIG"    ��        ��
"NOR+YEL"������������������"HIB" �m_________"HIR"��������"HIB"_________ �m"HIG"    ��        ��
"NOR+GRN"^^^^^^^^^^^^^^^^^^^                             ^^^^^^^^^^^^^^^^^^^^^^^
"NOR);
set("light",1);
set("objects",([
]));

set("exits",([  
"west" : __DIR__"workroom1",
]));
set("hide_exits",([  
]));

set("no_clean_up", 1);
create_door("west","����j��","east",DOOR_LOCKED,"redkey");
setup();
}

void init()
{
 add_action("do_ip","ip");
}

int do_ip(string arg)
{
 object *player;
 int x,i,ip1,j;
 string list,temp;
 
 list="\n";
 player=users();
 x=0;
 for(j=127;204>j;j++)
 {
 for(i=0;sizeof(player)>i;i++)
 {
  sscanf( query_ip_number(player[i]),"%d.%s",ip1,temp);
  if(ip1==j) list+=sprintf( "%12s (%12s) %s \n",player[i]->query("name"),player[i]->query("id"),query_ip_number(player[i]));
 }
}

 write(list);
 return 1;
}
