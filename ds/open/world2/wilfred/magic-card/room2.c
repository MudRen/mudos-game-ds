// �������ȵP�C��  Wilfred@DS

#include <ansi2.h>
#define MAX 8   // �]�w�@���iŪ���h�ֵP, �̤֬� 5, �ܦh���n�W�L 10 ����, �t�~���@�]�w�n�t�X�P���ӥ�
inherit ROOM;

mixed *arr = allocate(5);
mixed *p1 = allocate(5);
mixed *p2 = allocate(5);
int *used1 = allocate(5);
int *used2 = allocate(5);
int *place = allocate(9);
string *place_n = allocate(9);

int do_restart(int index);
int do_show();
int check(int x, int y, int z, int w, int v);
string front(int index);
string c_side(int index);
string c_use(int index, int pp);

void create()
{
  set ("short", HIG"�C����"NOR);
  set ("long", @LONG

�o�̬O�M�����ѵ� Magic-Card �����a�C���Ϊ����a�C
�ϥλ����Ьݯd��1 (post1)�A�C���W�h�Ьݯd��2 (post2)

LONG
);
  set("exits", ([
    "up"   : __DIR__"room1",
]));
  set("item_desc", ([
  "post1" : @LONG

�Х��N 8 �i�P��J�P�����A�~��i��C���C

    addin      �[�J�P��
    start      �}�l�C��
    restart    ���s�]�w�C��
    show �� .  �ݵP��

 play �d�� on �Ʀr   ��m ���w�d��[�ѥ��ܥk](0 ~ 4) �� ���w��m(0 ~ 8) �W

         �p�U��:
     �~�w�s�w�s�w��
     �x���x���x���x
     �u�w�q�w�q�w�t
     �x���x���x���x
     �u�w�q�w�q�w�t
     �x���x���x���x
     ���w�r�w�r�w��
     [�d��]. �d���W

�`�N�ƶ�: ���F�קK�@�Ǥ����n���·СA�бz
          �̦n���W�u�a�@�ӵP���Ӷi��C���C

                            -Wilfred@DS-  Ver 1.4a
LONG,

  "post2" : @LONG

�򥻤W���C����ӪžԤh�K�Ҫ����ȵP�C���@�ˡA�Y�������C���W���H�i���L���ݡC

�W�h:  1. �C�ӤH�b�}�l�ɦ����i��P�A��M�o�Ǥ�P�O���}���C
       2. �C�@�i�d�������|�ӼƦr�A�W�U���k�A�o�ǼƦr�N��o�P�������O�C
       3. �N�䤤�@�i��P���E����̡A�ˬd�A�񪺳o�檺�|�P���|�Ӯ�l�A�p�U
     �~�w�s�w�s�w��
     �x  �x  �x��x �A�����ˬd "X" �o�Ǯ�l���P�A�p�G�A���Ʀr�񥦤j�A����
     �u�w�q�w�q�w�t �A�i�H�N��誺�P�令�ۤv���C��C
     �x  �x��x�A�x
     �u�w�q�w�q�w�t ������Ʀr�H��k��²��A�p�G�A�n��A�W�診���A����
     �x  �x  �x��x �A���Ʀr�N�O��� "�W" �����ӡA���h�ۤϡA�L�n�� "�U"
     ���w�r�w�r�w�� ���o�ӼƦr��A��C

       4. �̫�u�n�ݽ֪��C���l���h�A�ִN��F�o�����ɡC
       PS. �t�η|�ˬd�A���P���A�q 8 �i���� 5 �i����ƨӧ@�������C������ơC
           �ҥH�z�Q�i��C���A�ܤ֭n�ǳƤ@�ӵP����K�i�P�~��C

                                                              Have Fun !!
                                               -Wilfred@DS-
LONG,

]));
  set("light",1);
  set("no_call",1);
  set("no_goto",1);
  set("no_fight",1);
  set("no_cast",1);
  set("no_kill",1);
  setup();
  do_restart(1);
}

void init()
{
  add_action("do_addin","addin");
  add_action("do_start","start");
  add_action("do_restart","restart");
  add_action("do_show","show");
  add_action("do_show",".");
  add_action("do_play","play");
}

int do_addin()
{
  object me = this_player();
  object obj, *inv;
  string side;
  int i;

  if(query("p1/id") && query("p2/id")) return notify_fail("�v�g����ӤH�[�J�o���C���F.\n");
  if(query("is_game")) return notify_fail("�{�b�C�����b�i�椤.\n");
  if(query("p1/id") == me->query("id") || query("p2/id") == me->query("id"))
    return notify_fail("�A�v�[�J�F�o���C��.\n");
  if(!obj = present("card box",me)) return notify_fail("�A�èS���a�P���C\n");

  inv = all_inventory(obj);
  if(sizeof(inv) != MAX) return notify_fail("�Х��b�P���̩� "+MAX+" �i Magic�C���d�C\n");
  for(i=0;i<sizeof(inv);i++)
    if(inv[i]->query("id") != "magic card") return notify_fail("�Х��b�P���̩� "+MAX+" �i Magic�C���d�C\n");

  if(!query("p1/id")) side = "1";
    else side = "2";

  set("p"+side+"/id", me->query("id"));
  for(i=0;i<sizeof(inv);i++)
    add("p"+side+"/card-data", ({inv[i]}) );

  tell_room(this_object(),HIW+me->query("name")+"�[�J�F�o���C��.\n"NOR);
  return 1;
}

int do_start()
{
  int i, j, k, index;
  object *temp1, *temp2;
  if(query("is_game")) return notify_fail("�C���v�g�}�l�F.\n");
  if(!query("p1/id") || !query("p2/id")) return notify_fail("���ݭn��ӤH�~��i��C��.\n");

  temp1 = query("p1/card-data");
  temp2 = query("p2/card-data");

  for(i=0;i<5;i++)
  {
    index = random(sizeof(temp1));
    if(p1[i] == temp1[index])
    {
      i--;
      continue;
    }

    k = 0;
    for(j=0;j<5;j++)
      if(temp1[index] == p1[j]) k++;
    if(k)
    {
      i--;
      continue;
    }

    p1[i] = temp1[index];
  }

  for(i=0;i<5;i++)
  {
    index = random(sizeof(temp2));
    if(p2[i] == temp2[index])
    {
      i--;
      continue;
    }

    k = 0;
    for(j=0;j<5;j++)
      if(temp2[index] == p2[j]) k++;
    if(k)
    {
      i--;
      continue;
    }

    p2[i] = temp2[index];
  }
  set("is_game",1);

  tell_room(this_object(),HIC"�t��Ū������C���d����� .... ���Ū�� ok.\n�C���{�b�}�l.\n\n"NOR);
  tell_room(this_object(),HIG"��"+query("p1/id")+"���X�P.\n"NOR);
  set("now_side", query("p1/id"));
  return 1;
}

int do_restart(int index)
{
  object me = this_player();
  int i, j;

  if(index && query("is_game")) return 0;
  for(i=0;i<5;i++)
    arr[i] = allocate(5);

  for(i=0;i<5;i++)
    for(j=0;j<5;j++)
      arr[i][j] = allocate(4);

  p1 = allocate(5);
  p2 = allocate(5);
  place = allocate(9);
  place_n = allocate(9);
  used1 = allocate(5);
  used2 = allocate(5);

  for(i=0;i<9;i++)
    place_n[i] = " ";

  delete("is_game");
  delete("p1/id");
  delete("p1/card-data");
  delete("p2/id");
  delete("p2/card-data");

  if(!me) me = this_object();
  tell_room(this_object(), HIY+me->query("name")+"�N�C�����s�]�w�F.\n"NOR);
  return 1;
}

int do_show()
{
  string t_msg = "";
  string *p_msg = allocate(2);
  string *msg = allocate(8);
  string index;
  string *temp_msg = allocate(4);
  string *temp_n = allocate(5);
  mixed *temp_pow = allocate(5);
  int i, j, k;

  if(!query("is_game")) return notify_fail("�C���|���}�l�A�P��O�Ū�.\n");

  msg[0] = NOR+HBGRN+HIG"�@"U"�@�@�@�@�@�@"NOR;
  msg[1] = NOR+HBGRN+HIG"�y"NOR+HIW"%s%|12s"NOR;
  msg[2] = NOR+HBGRN+HIG"�y"NOR+HIW"%s%5s�@%-5s"NOR;
  msg[3] = NOR+HBGRN+HIG"�y"NOR+HIW"%s%|12s"NOR;
//  msg[4] = NOR+HBGRN+HIG"�y"NOR"%12s"NOR;
  msg[5] = NOR+HBGRN+HIG"�y"NOR+HIY"%s%|12s"NOR;
  msg[6] = NOR+HBGRN+HIG+U"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@"NOR;
  msg[7] = NOR+HBGRN+HIG"�y\n"NOR;

  for(k=0;k<3;k++)
    for(i=0;i<6;i++)
    {
      if(i == 4) continue;    // �N msg[4] �󤧤���, ��]: �y���e���V��
      t_msg += "�@�@�@";
      for(j=0;j<3;j++)
        t_msg += msg[i];
      t_msg += msg[7];
    }
  t_msg += "�@�@�@";
  t_msg += msg[6];
  t_msg += msg[7];

  t_msg = sprintf(t_msg,
// ------------------ 0 ~ 2 ------------------------
c_side(0),front(arr[1][1][0]),
c_side(1),front(arr[1][2][0]),
c_side(2),front(arr[1][3][0]),

c_side(0),front(arr[1][1][3]),front(arr[1][1][1]),
c_side(1),front(arr[1][2][3]),front(arr[1][2][1]),
c_side(2),front(arr[1][3][3]),front(arr[1][3][1]),

c_side(0),front(arr[1][1][2]),  // c_side(0),
c_side(1),front(arr[1][2][2]),  // c_side(1),
c_side(2),front(arr[1][3][2]),  // c_side(2),

c_side(0),place_n[0],
c_side(1),place_n[1],
c_side(2),place_n[2],

// ------------------ 3 ~ 5 ------------------------
c_side(3),front(arr[2][1][0]),
c_side(4),front(arr[2][2][0]),
c_side(5),front(arr[2][3][0]),

c_side(3),front(arr[2][1][3]),front(arr[2][1][1]),
c_side(4),front(arr[2][2][3]),front(arr[2][2][1]),
c_side(5),front(arr[2][3][3]),front(arr[2][3][1]),

c_side(3),front(arr[2][1][2]),  // c_side(3),
c_side(4),front(arr[2][2][2]),  // c_side(4),
c_side(5),front(arr[2][3][2]),  // c_side(5),

c_side(3),place_n[3],
c_side(4),place_n[4],
c_side(5),place_n[5],

// ------------------ 6 ~ 8 ------------------------
c_side(6),front(arr[3][1][0]),
c_side(7),front(arr[3][2][0]),
c_side(8),front(arr[3][3][0]),

c_side(6),front(arr[3][1][3]),front(arr[3][1][1]),
c_side(7),front(arr[3][2][3]),front(arr[3][2][1]),
c_side(8),front(arr[3][3][3]),front(arr[3][3][1]),

c_side(6),front(arr[3][1][2]),  // c_side(6),
c_side(7),front(arr[3][2][2]),  // c_side(7),
c_side(8),front(arr[3][3][2]),  // c_side(8),

c_side(6),place_n[6],
c_side(7),place_n[7],
c_side(8),place_n[8]

);

  temp_msg[0] = "%s%|12s";
  temp_msg[1] = "%s%|12s";
  temp_msg[2] = "%s%5s�@%-5s";
  temp_msg[3] = "%s%|12s";

  p_msg[0] = HIC"���a "HIR+query("p1/id")+HIC" ���P��:\n"NOR;
  p_msg[1] = HIC"���a "HIB+query("p2/id")+HIC" ���P��:\n"NOR;
  for(k=0;k<2;k++)
    for(j=0;j<4;j++)
    {
      for(i=0;i<5;i++)
      {
        p_msg[k] += temp_msg[j];
      }
      p_msg[k] += "\n";
    }

  for(i=0;i<2;i++)
  {
    if(i == 0)
    {
      for(j=0;j<5;j++)
        temp_pow[j] = allocate(4);
      for(j=0;j<5;j++)
      {
        temp_n[j] = p1[j]->query("short");
        temp_pow[j] = p1[j]->query("pow");
      }
    }
    else
    {
      for(j=0;j<5;j++)
        temp_pow[j] = allocate(4);
      for(j=0;j<5;j++)
      {
        temp_n[j] = p2[j]->query("short");
        temp_pow[j] = p2[j]->query("pow");
      }
    }

  p_msg[i] = sprintf(p_msg[i],
c_use(0,i),temp_n[0],
c_use(1,i),temp_n[1],
c_use(2,i),temp_n[2],
c_use(3,i),temp_n[3],
c_use(4,i),temp_n[4],

c_use(0,i),front(temp_pow[0][0]),
c_use(1,i),front(temp_pow[1][0]),
c_use(2,i),front(temp_pow[2][0]),
c_use(3,i),front(temp_pow[3][0]),
c_use(4,i),front(temp_pow[4][0]),

c_use(0,i),front(temp_pow[0][3]),front(temp_pow[0][1]),
c_use(1,i),front(temp_pow[1][3]),front(temp_pow[1][1]),
c_use(2,i),front(temp_pow[2][3]),front(temp_pow[2][1]),
c_use(3,i),front(temp_pow[3][3]),front(temp_pow[3][1]),
c_use(4,i),front(temp_pow[4][3]),front(temp_pow[4][1]),

c_use(0,i),front(temp_pow[0][2]),
c_use(1,i),front(temp_pow[1][2]),
c_use(2,i),front(temp_pow[2][2]),
c_use(3,i),front(temp_pow[3][2]),
c_use(4,i),front(temp_pow[4][2])
);

  }
  if(this_player()->query("id") != query("q1/id") && this_player()->query("id") != query("q2/id"))
    write(p_msg[0]);
  else
    if(this_player()->query("id") == query("p2/id")) write(p_msg[0]);
      else write(p_msg[1]);

  write("\n"+t_msg+"\n");

  if(this_player()->query("id") != query("q1/id") && this_player()->query("id") != query("q2/id"))
    write(p_msg[1]);
  else
    if(this_player()->query("id") == query("p2/id")) write(p_msg[1]);
      else write(p_msg[0]);

  return 1;
}

string c_use(int index, int pp)
{
  string *msg = ({HIW,BOLD+BLK});
  if(pp == 0) return msg[used1[index]];
    else return msg[used2[index]];
}

string c_side(int index)
{
  // ���⪺�H������
  string *msg = ({BBLK,HBRED,HBBLU});
  return msg[place[index]];
}

int do_play(string str)
{
  object me = this_player();
  int num, side, pp;
  int i, temp;
  int x, y;

  if(!query("is_game")) return notify_fail("�C���|���}�l.\n");
  if(query("p1/id") != me->query("id") && query("p2/id") != me->query("id"))
    return notify_fail("�o���C����A�S�����Y.\n");
  if(query("now_side") != this_player()->query("id")) return notify_fail("�٨S����A.\n");

  if(sscanf(str,"%d on %d",num,side) != 2) return notify_fail("<���O�榡: play �d�� on ��m>.\n");
  if(num < 0 || num > 4) return notify_fail("�d���Ы��w�b 0 ~ 4 ����.\n");
  if(side < 0 || side > 8) return notify_fail("�Ʀr�Ы��w�b 0 ~ 8 ����.\n");

  if(place[side] != 0) return notify_fail("�o��m�v���g���P�F.\n");

  x = (side / 3)+1;
  y = (side % 3)+1;
  temp = side;

  if(query("now_side") == query("p1/id"))
  {
    if(used1[num] == 1) return notify_fail("�o�i�P�v�ϥιL�F.\n");
    tell_room(this_object(),NOR+WHT+this_player()->query("name")+"�b "+temp+" ����m�W��F�@�i�P.\n");
    arr[x][y] = p1[num]->query("pow");
    pp = 1;
    used1[num] = 1;
    place_n[side] = p1[num]->query("short");
  }
  else
  {
    if(used2[num] == 1) return notify_fail("�o�i�P�v�ϥιL�F.\n");
    tell_room(this_object(),NOR+WHT+this_player()->query("name")+"�b "+temp+" ����m�W��F�@�i�P.\n");
    arr[x][y] = p2[num]->query("pow");
    pp = 2;
    used2[num] = 1;
    place_n[side] = p2[num]->query("short");
  }

  place[side] = pp;
  if(query("now_side") == query("p1/id")) set("now_side",query("p2/id"));
    else  set("now_side",query("p1/id"));

  for(i=0;i<4;i++)
    if(check(x, y, i, pp, side) == 1) tell_room(this_object(),HIC+this_player()->query("name")+"���\\���N��⪺�@�i�P½��.\n");

  do_show();

  for(i=0;i<9;i++)
    if(place[i] == 0)
    {
      if(pp == 1) tell_room(this_object(),HIW+"�{�b�� "HIB+query("p2/id")+HIW" �X�P�F.\n"NOR);
        else tell_room(this_object(),HIW+"�{�b�� "HIR+query("p1/id")+HIW" �X�P�F.\n"NOR);
      return 1;
    }

  tell_room(this_object(),HIG+"  G.A.M.E  is  O.V.E.R\n"NOR);
  return 1;
}

int check(int x, int y, int z, int w, int v)
{
  int temp1 = x, temp2 = y, temp3 = z, temp4 = v;
  switch(z)
  {
    case 0 : x--;
             break;
    case 1 : y++;
             break;
    case 2 : x++;
             break;
    case 3 : y--;
             break;
  }
  if(x < 1 || x > 3 || y < 1 || y > 3) return 0;
  v = ( (x-1) * 3 ) + ( y - 1 );
  if(v < 0 || v > 8) return 0;
  z += 2;
  if(z > 3) z -= 4;
  if(arr[temp1][temp2][temp3] > arr[x][y][z] && place[v] > 0 && place[temp4] != place[v])
  {
    place[v] = w;
    return 1;
  }

  return 0;
}

string front(int index)
{
  string *str = ({"�@","��","��","��","��","��","��","��","��","��","��"});
  if(!index) index = 0;
  return str[index];
}

void reset()
{
  if(!do_restart(1)) return;
  ::reset();
}

