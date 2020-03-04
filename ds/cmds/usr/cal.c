// cal.c ���� unix �W�� cal �R�O
// �y�k: cal �~ ��
// 1997 3 10 wade@Fantasy.Space    jjchen@ice.ntnu.edu.tw
// �w��y�ǥ��{��, �ЫO�d������

#include <localtime.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string  *ani = ({ "��", "��", "��", "��", "�s", "�D",
                 "��", "��", "�U", "��", "��", "��" });

// �o�����M�O #define �Ӫ�, �i�O�u�n��ʨ��, �|�v�T�P������k
// �Ш����U���Q�ӬP�������@�檺����
#define FIRSTYEAR	1911

// ���~���~�C�뤧���
int *SolarCal = ({ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 });

// �D�����~�O�_���|�~, ��^ 0 �����~, 1 ���|�~
int GetLeap (int year)
{
  if ( year % 400 == 0 )        // ���~�i�Q�|�ʾ㰣���ܤ@�w�O��~
    return 1;                   // �p 1600, 2000 ����~
  else if ( year % 100 == 0 )   // �p�G�Q�@�ʾ㰣�o����Q�|�ʾ㰣, �h�����~
    return 0;                   // �p 1800, 1900 �����~
  else if ( year % 4 == 0 )     // ���O�@�ʪ����ƫo�O�|������, �h����~
    return 1;                   // �p 1992, 1996, 2000, 2004 ����~
  else                          // ��l�Ҭ����~
    return 0;
}

int main(object me, string arg)
{
  mixed *local;
  int	leap;		// �O�_��~
  int	yy, mm, dd;	// �n�d�ߪ����
  int	ty, tm, td;	// ���Ѫ����
  int	acc;		// �ֿn�Ѽ�, �ΨӺ�P���X�Ϊ�
  int	Weekday;	// ���몺�Ĥ@�Ѭ��P���X
  int	d;		// �Ӥ몺�Ѽ�
  int	i;

  // ���o���Ѫ����
  local = localtime(time());
  ty = local[LT_YEAR];
  tm = local[LT_MON]+1;
  td = local[LT_MDAY];

  if (!arg || arg == "") {	// �����
    yy = ty;
    mm = tm;
    dd = td;
  }
  else {			// ���w�����
    if (!sscanf (arg, "%d%d", yy, mm) == 2) {
      printf ("�y�k: cal �~ ��\n");
      return 1;
    }
    yy += 1911;
    dd = td;
  }
  if (yy < FIRSTYEAR) {
    printf ("�藍�_, �ثe�u���Ѥ��إ��� %d �~�H�᪺���.\n", FIRSTYEAR-1911);
    return 1;
  }
  if (mm < 1 || mm > 12) {
    printf ("�u��@���Q�G�붡.\n");
    return 1;
  }

  // �O�_����~
  leap = GetLeap ( yy );
  // �ѬO�_��~�p��Ӥ몺�Ѽ�
  if ( mm == 1 )	// �G��
    d = leap + 28;
  else
    d = SolarCal[mm-1];

  acc = 0;
  // �p��ֿn��h�~����� from ���� FIRSTYEAR�~
  for (i=FIRSTYEAR; i<yy; i++)
    acc = acc + 365 + GetLeap (i);
  // �p��ֿn��W�Ӥ몺���
  for (i=1; i<mm; i++)
    acc = acc + SolarCal[i-1];
  if (mm > 2 && GetLeap (yy)) acc++;	// ���~��~�[�@��

  // ����Ĥ@�骺�P����
  // ********** �o�䪺��k�O�]�� 1911 �~�� 1 �� 1 ��O�P���� **********
  Weekday = acc % 7;

  printf ("�i���� %d �~ %d ��j-- �u%s�~�v\n\n�� �@ �G �T �| �� ��\n",
          yy-1911, mm, ani[(yy-112)%12]);
  for (i=0; i<Weekday; i++)
    printf ("   ");
  for (i=1; i<=d; i++) {
    if ((Weekday + i) % 7 == 1)
      printf ("\n%s%2d %s", HIR, i, NOR);
    else if (yy == ty && mm == tm && td == i)
      printf ("%s%2d %s", HIY, i, NOR);
    else
      printf ("%2d ", i);
  }

  printf ("\n\n");
  return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : cal �� ��
���O���� :
	   �����O�i�H�Ψ���ܤ��, �Ҧp:
	   cal 86 3
 
�S�O�P��:
	- wade@Fantasy.Space
	- jjchen@ice.ntnu.edu.tw

HELP
    );
    return 1;
}
