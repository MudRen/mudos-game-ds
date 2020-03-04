//boat.c 
//update by luky. 1998.11.12
#include <ansi.h>
#include <path.h>
#define TIME_SPAN tt
#define UP_DOOR "climb"
#define DOWN_DOOR "out"
inherit ROOM;
int index=1;
int close_time;
int indexp=0;
int stay=1;
string *place=({
LUKY+"pearl/sand2",
LUKY+"pearl/pearl_32",
});
int tt=30;
void start();
void boat(string);
string query_filename()
{
  return place[index];
}
int getall()
{
  int i;
  for(i=0;i<sizeof(place);i++)
    if(stay)
      write(sprintf("%2d %10s %s %s \n",
           i+1,
           i==indexp ? HIY"�ثe���b->"NOR:"  ",
           place[i]->query("short"),
wiz_level(this_player())>=wiz_level("(admin)")?"=> ("+place[i]+")":"
"
             ));
     else
      write(sprintf("%2d %8s %s %s \n",
           i+1,
           i==index ? HIY"�U�@��->"NOR:" ",
           place[i]->query("short"),
 wiz_level(this_player())>=wiz_level("(admin)")?"=> ("+place[i]+")":"
"
             ));

  return 1;
}

void create()
{
//seteuid(getuid());
set("short","[1;31m�j����[0m");
set("name","[1;31m�j���ɹ[m");
set("id","cancership");
set("long", @LONG
              ���i�i�i��                  ���i�i�i��
            ���i�i��  ����              ���i��  ���i��
        ���i�i�i��                                 ���i��
      ���i�i�i�i���b�b���i��             ��      ���i�i�i��
      �i�i��  ���i�i�i�i��               ���i�i�i�i��  ���i��
      ���i��                ��          ��               �i��
        ���i�i��            ��          ��           ���i��
             ���i�i�� �b�d�e�g�g�h�i�h�g�g�e�d�b���i�i��
            �b�d�f�h�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�h�f�d�b
    ���i�i�����i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�����i�i��
  ����    �����i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i����    ����
����          ���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i��          ����
        ���i�i���i�i�i�i�h�g�f�e�d�c�d�e�f�g�h�i�i�i�i���i��
      ����      ���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i��    ����
    ����    ���i�����i�i�i�i�i�i�i�i�i�i�i�i�i�i�����i��    ����
    ��    ����    �������i�i�i�i�i�i�i�i�i�i�i������  ����    ��
          �i      �i        ���i�i�i�i�i��        �i    �i
          ��      ����                          ����    �� 
LONG);
set("unit","��");
set("light",1);
call_out("boat",0,place[index]->query("short"));
}
void init()
{
        object ob;
        ob=this_player();
        start();
  add_action("getall","list");

}

void start()
{
    object me;
    me=this_player();
    message_vision(HIG"$N[1;32m�n�W�F"+this_object()->query("name")+"�C\n"NOR,me);
}

int getman()
{
  object *inv;
  int i,all;
  all=0;
  inv=all_inventory(this_object());
//  for(i=0;i<sizeof(inv);i++)
//  if(userp(inv[i]))all++;
  all=sizeof(inv);
  return all;
}

void boat(string ss)
{
  object ob,this_ship,temp_ship,ob1,ob2;
  string s;
  mapping ex;
  this_ship=this_object();
  set("exits",([
  DOWN_DOOR: place[index],
  ]));
  s=sprintf(HIR"�j���ɤw��F [1;34m%s[0m\n"NOR
  HIC"�ثe���ɤW���ȫ��`�@�� %d �ӤH\n"NOR, (place[index])->query("short")
  , getman());
  set("long",HIG"�A�V���~��h�A���M�o�{"+s+"\n\n "HIY+"list"NOR+"�i�d�ݪu�~���a������\n "NOR);
  write(s+"�A�ݨ쵡�~�������O:\n"+place[index]->query("long")+"\n");
  write(HIW"�n���}���ȫȽбƶ��U��(out)..\n"+NOR+"\n");
  setup();

  ex=place[index]->query("exits");
// add by Nilekil
        ob1=new(LUKY+"pearl/tempship.c");
        ob2=find_object(place[index]);
        ob1->move(ob2);
  tell_room(place[index],
HIC"[1;31m�j����[1;36m�C�C����i�F��f.....\n"NOR);
  if(mapp(ex))
  place[index]->set("exits",(mapping)(place[index]->query("exits"))+
  ([ UP_DOOR : base_name(this_object()), ]) );
  else {
    ex=([]);
 ex[UP_DOOR]=base_name(this_object());
    place[index]->set("exits",ex);
  }
  indexp=index;
  index++;
  if(index==sizeof(place)) index=0;
remove_call_out("boat");
close_time=20;
  stay=1;
  call_out("closedoor1",0,"�����a�b "+place[indexp]->query("short"));
}
void closedoor1(string s)
{
  object this_ship,temp_ship,ob1,ob2;
  mapping ex;
this_ship=this_object();
  if(close_time>0)
{
//write("�٦�" +HIY+sprintf("%d",close_time)+NOR+"��N�n�X�o�F\n");
tell_room(place[indexp],"�j���ɴN�n�X��F!�Эn�f�����ȫȻ��֪��W��("+UP_DOOR+").....\n"NOR);
close_time -=10;
remove_call_out("closedoor1");
call_out("closedoor1",10,"���a�b "+place[indexp]->query("short"));
} else 
{
write(HIW"���ɾ_�ʤF�@�U...�w�w����"+place[index]->query("short")+HIW+"�e�i...\n"NOR);
// add by nilekil
ob1=find_object(place[indexp]);
ob2=present("cancer",ob1); 
if (!ob2)         { 
                tell_room(place[indexp],"�j����ı�o�Ӳ�..���_�Ӥ��W�Z�F!!\n");
         destruct(this_ship); // Luky
        }
        else { 
                tell_room(place[indexp],"�j���ɦ����i�y, ����������...\n");
                destruct(ob2);
        }
tell_room(place[indexp],HIR"�j����[1;36m�w�w�����}�F��f�A�}�l��"+
place[index]->query("short")+HIC"����..[0m\n");
set("long","�A�{�b���� "+place[indexp]->query("short")+
   " ��p�� "+place[index]->query("short")+" �~��...\n"+
   "�i�� "+HIY+"list"+NOR+" �Ӭd�ݪu�~�g�L����\n\n");
   ex=this_object()->query("exits");
   if(mapp(ex)) map_delete(ex,DOWN_DOOR);
   ex=place[indexp]->query("exits");
   if(mapp(ex)) map_delete(ex,UP_DOOR);
   place[indexp]->set("exits",ex);
   remove_call_out("closedoor1");
   stay=0;
call_out("boat",TIME_SPAN,"���}�� "+place[index]->query("short")+"��");
  }
}
