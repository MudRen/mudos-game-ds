// 集換式紙牌遊戲  Wilfred@DS

#include <ansi2.h>
#define MAX 8   // 設定一次可讀取多少牌, 最少為 5, 至多不要超過 10 為佳, 另外此一設定要配合牌盒來用
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
  set ("short", HIG"遊戲室"NOR);
  set ("long", @LONG

這裡是專門提供給 Magic-Card 的玩家遊戲用的場地。
使用說明請看留言1 (post1)，遊戲規則請看留言2 (post2)

LONG
);
  set("exits", ([
    "south"   : __DIR__"room2",
]));
  set("item_desc", ([
  "post1" : @LONG

請先將 8 張牌放入牌盒中，才能進行遊戲。

    addin      加入牌局
    start      開始遊戲
    restart    重新設定遊戲
    show 或 .  看牌桌

 play 卡號 on 數字   放置 指定卡號[由左至右](0 ~ 4) 至 指定位置(0 ~ 8) 上

         如下圖:
     ╭─┬─┬─╮
     │０│１│２│
     ├─┼─┼─┤
     │３│４│５│
     ├─┼─┼─┤
     │６│７│８│
     ╰─┴─┴─╯
     [卡號]. 卡片名

注意事項: 為了避免一些不必要的麻煩，請您
          最好身上只帶一個牌盒來進行遊戲。

                            -Wilfred@DS-  Ver 1.4a
LONG,

  "post2" : @LONG

基本上此遊戲跟太空戰士八所附之紙牌遊戲一樣，若熟知此遊戲規的人可跳過不看。

規則:  1. 每個人在開始時有五張手牌，當然這些手牌是公開的。
       2. 每一張卡片都有四個數字，上下左右，這些數字代表這牌的攻擊力。
       3. 將其中一張手牌放到九公格裡，檢查你放的這格的四周的四個格子，如下
     ╭─┬─┬─╮
     │  │  │Ｘ│ 你必需檢查 "X" 這些格子的牌，如果你的數字比它大，那麼
     ├─┼─┼─┤ 你可以將對方的牌改成自己的顏色。
     │  │Ｘ│你│
     ├─┼─┼─┤ 怎麼比較數字？方法很簡單，如果你要跟你上方那格比，那麼
     │  │  │Ｘ│ 你的數字就是位於 "上" 的那個，對方則相反，他要拿 "下"
     ╰─┴─┴─╯ 的這個數字跟你比。

       4. 最後只要看誰的顏色格子較多，誰就鸁了這場比賽。
       PS. 系統會檢查你的牌盒，從 8 張中抽 5 張的資料來作為此次遊戲的資料。
           所以您想進行遊戲，至少要準備一個牌盒跟八張牌才行。

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

  if(query("p1/id") && query("p2/id")) return notify_fail("己經有兩個人加入這場遊戲了.\n");
  if(query("is_game")) return notify_fail("現在遊戲正在進行中.\n");
  if(query("p1/id") == me->query("id") || query("p2/id") == me->query("id"))
    return notify_fail("你己加入了這場遊戲.\n");
  if(!obj = present("card box",me)) return notify_fail("你並沒有帶牌盒。\n");

  inv = all_inventory(obj);
  if(sizeof(inv) != MAX) return notify_fail("請先在牌盒裡放 "+MAX+" 張 Magic遊戲卡。\n");
  for(i=0;i<sizeof(inv);i++)
    if(inv[i]->query("id") != "magic card") return notify_fail("請先在牌盒裡放 "+MAX+" 張 Magic遊戲卡。\n");

  if(!query("p1/id")) side = "1";
    else side = "2";

  set("p"+side+"/id", me->query("id"));
  for(i=0;i<sizeof(inv);i++)
    add("p"+side+"/card-data", ({inv[i]}) );

  tell_room(this_object(),HIW+me->query("name")+"加入了這場遊戲.\n"NOR);
  return 1;
}

int do_start()
{
  int i, j, k, index;
  object *temp1, *temp2;
  if(query("is_game")) return notify_fail("遊戲己經開始了.\n");
  if(!query("p1/id") || !query("p2/id")) return notify_fail("必需要兩個人才能進行遊戲.\n");

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

  tell_room(this_object(),HIC"系統讀取雙方遊戲卡之資料 .... 資料讀取 ok.\n遊戲現在開始.\n\n"NOR);
  tell_room(this_object(),HIG"請"+query("p1/id")+"先出牌.\n"NOR);
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
  tell_room(this_object(), HIY+me->query("name")+"將遊戲重新設定了.\n"NOR);
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

  if(!query("is_game")) return notify_fail("遊戲尚未開始，牌桌是空的.\n");

  msg[0] = NOR+HBGRN+HIG"　"U"　　　　　　"NOR;
  msg[1] = NOR+HBGRN+HIG"▕"NOR+HIW"%s%|12s"NOR;
  msg[2] = NOR+HBGRN+HIG"▕"NOR+HIW"%s%5s　%-5s"NOR;
  msg[3] = NOR+HBGRN+HIG"▕"NOR+HIW"%s%|12s"NOR;
//  msg[4] = NOR+HBGRN+HIG"▕"NOR"%12s"NOR;
  msg[5] = NOR+HBGRN+HIG"▕"NOR+HIY"%s%|12s"NOR;
  msg[6] = NOR+HBGRN+HIG+U"　　　　　　　　　　　　　　　　　　　　　"NOR;
  msg[7] = NOR+HBGRN+HIG"▕\n"NOR;

  for(k=0;k<3;k++)
    for(i=0;i<6;i++)
    {
      if(i == 4) continue;    // 將 msg[4] 棄之不用, 原因: 造成畫面混亂
      t_msg += "　　　";
      for(j=0;j<3;j++)
        t_msg += msg[i];
      t_msg += msg[7];
    }
  t_msg += "　　　";
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
  temp_msg[2] = "%s%5s　%-5s";
  temp_msg[3] = "%s%|12s";

  p_msg[0] = HIC"玩家 "HIR+query("p1/id")+HIC" 的牌為:\n"NOR;
  p_msg[1] = HIC"玩家 "HIB+query("p2/id")+HIC" 的牌為:\n"NOR;
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
  // 先手的人為紅色
  string *msg = ({BBLK,HBRED,HBBLU});
  return msg[place[index]];
}

int do_play(string str)
{
  object me = this_player();
  int num, side, pp;
  int i, temp;
  int x, y;

  if(!query("is_game")) return notify_fail("遊戲尚未開始.\n");
  if(query("p1/id") != me->query("id") && query("p2/id") != me->query("id"))
    return notify_fail("這場遊戲跟你沒有關係.\n");
  if(query("now_side") != this_player()->query("id")) return notify_fail("還沒輪到你.\n");

  if(sscanf(str,"%d on %d",num,side) != 2) return notify_fail("<指令格式: play 卡號 on 位置>.\n");
  if(num < 0 || num > 4) return notify_fail("卡號請指定在 0 ~ 4 之間.\n");
  if(side < 0 || side > 8) return notify_fail("數字請指定在 0 ~ 8 之間.\n");

  if(place[side] != 0) return notify_fail("這位置己有經有牌了.\n");

  x = (side / 3)+1;
  y = (side % 3)+1;
  temp = side;

  if(query("now_side") == query("p1/id"))
  {
    if(used1[num] == 1) return notify_fail("這張牌己使用過了.\n");
    tell_room(this_object(),NOR+WHT+this_player()->query("name")+"在 "+temp+" 的位置上放了一張牌.\n");
    arr[x][y] = p1[num]->query("pow");
    pp = 1;
    used1[num] = 1;
    place_n[side] = p1[num]->query("short");
  }
  else
  {
    if(used2[num] == 1) return notify_fail("這張牌己使用過了.\n");
    tell_room(this_object(),NOR+WHT+this_player()->query("name")+"在 "+temp+" 的位置上放了一張牌.\n");
    arr[x][y] = p2[num]->query("pow");
    pp = 2;
    used2[num] = 1;
    place_n[side] = p2[num]->query("short");
  }

  place[side] = pp;
  if(query("now_side") == query("p1/id")) set("now_side",query("p2/id"));
    else  set("now_side",query("p1/id"));

  for(i=0;i<4;i++)
    if(check(x, y, i, pp, side) == 1) tell_room(this_object(),HIC+this_player()->query("name")+"成功\的將對手的一張牌翻面.\n");

  do_show();

  for(i=0;i<9;i++)
    if(place[i] == 0)
    {
      if(pp == 1) tell_room(this_object(),HIW+"現在換 "HIB+query("p2/id")+HIW" 出牌了.\n"NOR);
        else tell_room(this_object(),HIW+"現在換 "HIR+query("p1/id")+HIW" 出牌了.\n"NOR);
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
  string *str = ({"　","１","２","３","４","５","６","７","８","９","Ａ"});
  if(!index) index = 0;
  return str[index];
}

void reset()
{
  if(!do_restart(1)) return;
  ::reset();
}

