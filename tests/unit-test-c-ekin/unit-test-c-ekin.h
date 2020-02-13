#ifndef __UNIT_TEST_C_EKIN_H__
#define __UNIT_TEST_C_EKIN_H__

/* LUT with initial velocities */
const double LUT_vel[][3] =
{{-1.5643224621482283e-03,4.8497508563925346e-04,-4.3352481732883966e-04},
{4.1676710257651452e-04,2.2858522230176587e-05,-6.1985040462745732e-04},
{-7.5611349562333923e-04,4.0710138209103827e-04,-4.6520198934056357e-04},
{-1.0716463354369357e-03,1.9399472344407333e-03,3.6805207892014988e-05},
{1.8845309488827741e-03,-9.6929654979601939e-04,-5.0590631889323786e-04},
{6.3850936177063688e-04,2.9439961625943489e-03,2.0290627741083355e-04},
{1.5417020528064903e-05,1.7854479210267119e-05,1.0061778727049613e-03},
{-1.4096631765204916e-03,6.6920838746400600e-04,-1.1440332398881235e-03},
{-1.1623287197336312e-03,1.6266211340761735e-03,1.3040008893057014e-03},
{1.3961661508013856e-03,3.5480038145712736e-05,-9.9101224232255817e-04},
{-7.8119282252798756e-04,8.0770620385540233e-04,-1.4741616364769391e-04},
{-8.4465150294226528e-04,-1.9923244287298695e-03,-6.2089699425759077e-04},
{4.8199317804818579e-04,2.6851883010136799e-04,2.8946202010011360e-05},
{-8.2433856370986945e-04,2.8766236402950288e-04,-6.7726146942851230e-04},
{1.0759225321624727e-03,-5.0652068703702471e-04,-8.1558579057040967e-04},
{-4.1654885401277715e-04,-2.1963115969871258e-03,4.7173893044170949e-04},
{3.3822271329348960e-03,-1.1094925187093363e-04,1.7960828583444049e-03},
{-4.5419241078412093e-04,-5.9345998636867009e-05,-5.7258946451372564e-04},
{-1.1899036421980488e-03,9.3983719885128869e-05,-5.8462360685180778e-04},
{3.7172749436126885e-04,1.9340413720264325e-03,1.4034788302775946e-03},
{1.7974246348577072e-04,1.0193612025409288e-03,4.9370272372543282e-04},
{-9.4461498382508897e-04,-1.5026896525989781e-03,9.1479102888999955e-05},
{-1.8939664944843942e-03,5.6369115520127778e-04,2.4325248949145196e-04},
{5.8057892769663175e-04,1.2299831371874594e-04,2.9629659010955246e-04},
{8.3145733665166094e-04,1.6024783547625206e-03,2.2561613876544880e-03},
{-3.3459474408059099e-04,-9.0138124644271826e-04,4.6451973781908732e-05},
{-1.4661492298318566e-03,-9.6700324227027277e-04,-1.2402619350327583e-03},
{2.2294716528019855e-04,-7.1757354452299765e-04,-1.3359945828925550e-03},
{3.5744852428510476e-04,-4.7176712674574758e-04,-1.2299995762011908e-03},
{-7.1013397780573531e-04,2.1818976630239278e-03,3.0517895276767340e-03},
{7.9633427864940574e-04,-3.3213284823899663e-05,-8.8375819004122126e-04},
{-1.0048962733085658e-03,-1.0338986950231507e-03,-1.2128201825351069e-03},
{6.1036336377894929e-04,9.2701621970857817e-04,-1.2537972128693620e-03},
{1.0520429442651071e-03,-8.4866067556637161e-04,-1.3560525458749155e-05},
{2.5814213260471724e-04,-7.5314897639645743e-04,8.0713082892823452e-04},
{-3.6385410005198736e-03,8.8146280046642606e-04,5.6477118870225215e-05},
{9.6333620309687013e-04,1.7133724036878372e-04,-6.2326101449483172e-04},
{1.3552473384443623e-03,6.8479283464214743e-04,1.7273048455913563e-03},
{2.5884589579386447e-03,-1.4321360648116401e-03,-3.0829116871650114e-04},
{-1.9464964022266687e-03,-6.1160752453349304e-04,1.2508357692460391e-03},
{2.0354460092287877e-03,-8.0047183425335712e-04,-7.6779326062273879e-05},
{-8.8078983167544410e-04,2.0527738907615478e-03,-4.8490967626695514e-04},
{-1.6226833552402415e-03,-4.4509205363786440e-04,5.7985161430016720e-04},
{-1.3846623789497004e-03,-8.1591443760356856e-04,3.5239524960511482e-04},
{8.4581719582112696e-05,4.4027379945299169e-04,7.8825448363930943e-04},
{1.9101264956063397e-04,-3.7541323533216431e-05,2.0232815584298586e-04},
{1.0507771398316642e-03,2.1703338837872421e-06,1.8721233841267814e-03},
{-1.1764360038119695e-03,-2.7051268798865438e-03,4.2626857615829489e-04},
{1.4811895380049227e-03,-8.6900359536064796e-04,-1.3508346585503553e-03},
{1.3876291076744002e-03,6.5070110767351664e-04,-6.1537705602631544e-05},
{-1.5265028980997747e-04,3.5305182092379836e-03,-3.5107439080411313e-04},
{1.2593135527188843e-03,-3.4770110188951111e-04,-3.2219440087892302e-03},
{-4.8839641798958239e-04,-1.0781245860584732e-03,-7.6447169214134084e-04},
{2.9537856402441307e-03,3.5708460303038737e-04,4.3965885540392521e-04},
{-9.2354805883572888e-04,-1.3750879594929264e-04,1.7566816252148881e-03},
{-8.4649245109681394e-05,-2.5830032329337755e-03,6.2136732242066585e-04},
{-7.8863228626065347e-04,-4.7987306164718428e-05,-7.6918205615324461e-05},
{-7.5715366119523408e-04,-8.8223969491051666e-04,-1.1130209071318147e-03},
{-1.5829995718074550e-03,-1.0023130948058853e-03,1.0105693656524083e-03},
{-9.7237564644641694e-04,-4.2306183690077959e-03,-1.7993911047256889e-03},
{2.5009355760304557e-03,-6.9762487866167910e-04,1.4240088170272963e-03},
{-2.1973523929318302e-04,2.2092313541290937e-05,8.3472986487536491e-05},
{1.1022471068800079e-03,-3.1173869715215023e-03,2.2862705719842859e-03},
{-1.2765414792041748e-03,8.2954964873239924e-04,8.6393605486046691e-07},
{1.8024567462803108e-03,-3.2357868878445974e-04,7.2049328401194016e-04},
{1.3369574268302883e-03,2.4197150221213766e-04,-2.4078296952019445e-04},
{-6.4367273480117029e-04,9.4544158572617176e-05,1.2224424402153017e-03},
{7.3861349744237207e-04,6.1538146539837915e-04,-1.0659904512438458e-04},
{-1.3869668138548187e-03,-1.5135537737600894e-03,-1.7700632516888342e-03},
{-1.2783209148195544e-03,-6.4363699635212640e-04,-6.3784434948207917e-04},
{-1.1486989458051769e-03,2.2414503838807933e-03,5.7721354683718497e-05},
{1.3168895876064066e-03,1.9570675664972955e-03,4.0936567386207711e-04},
{6.3073775671656379e-04,6.9398368370810696e-04,-2.7072142801711462e-03},
{-3.2393828021454760e-04,1.8032188549262072e-03,-8.7265713577056329e-04},
{2.0422470188389682e-04,-7.7369026089478630e-04,-1.3328071442246694e-03},
{-2.2226907938257076e-05,4.7885157053263603e-04,6.0068136092359822e-05},
{-1.4298413641215028e-03,-1.1674283659453153e-04,-3.7073258095465290e-04},
{-2.0611289910871505e-03,-7.1332431440348544e-04,1.2809266282339321e-04},
{-7.4275381512506605e-04,1.8409280327853588e-03,-1.4613152937356479e-03},
{-1.1017089795515253e-03,9.2440680189215501e-04,4.1040985295765773e-05},
{5.3072557614502406e-04,-1.9182563618355668e-03,6.6929180130627429e-04},
{-1.6469389079891580e-03,-3.3913862865732141e-04,-3.4603537121251295e-04},
{-7.4215102626457323e-04,-9.8513589889560684e-05,8.8892011842225927e-04},
{-3.0986258142986708e-04,2.3322786412505996e-03,1.1214740271337398e-03},
{-2.2588473708594786e-03,-3.7370321664764982e-04,2.6199219861683513e-03},
{1.5543286843928208e-03,3.0860432881096969e-04,-2.3276316538484460e-03},
{1.4014253099048656e-03,1.6989378445509686e-04,1.0862067754042389e-04},
{1.5485169419261718e-03,-2.5482574014883033e-04,1.6549301081433053e-03},
{8.3679284925556360e-04,2.6544605630854541e-03,-3.1978397990891830e-04},
{2.8867805091229137e-04,-9.5105410949532254e-04,-4.1906535931744601e-04},
{1.5677334410636003e-03,3.8398276164589067e-04,5.4230186211901119e-04},
{1.8828375897567346e-03,2.5974363433841984e-04,-5.4853918242744198e-04},
{-7.2191331833469923e-04,-9.3121561995775873e-04,-1.0102462549550035e-03},
{-2.5645967264587824e-04,-3.8300695089345021e-04,7.5308084406414243e-06},
{-6.9678200159030467e-04,1.9053736728726351e-03,-5.5375918909208023e-04},
{1.8765197796989418e-03,2.2251752214693724e-04,-8.5240569555193027e-04},
{6.5009741785571464e-04,1.5502364257396865e-03,-1.5320902037263414e-03},
{1.1552195131152949e-03,5.2576645590408585e-04,-9.7934306024165957e-05},
{-1.4419828777329281e-03,-2.0581943028127967e-03,-6.1455516747372426e-04},
{-1.8081813454125322e-03,2.0392408575730525e-04,5.2891537053608253e-04},
{8.3338854452045131e-04,8.4885016567212471e-05,-1.0314730467739900e-03},
{1.7861843205888382e-03,-1.4959403377944355e-03,5.0308057595438297e-04},
{-6.0451783799718114e-04,-1.9369920772084048e-03,8.3982235283629170e-04},
{8.7324422742439877e-04,1.6025909516322815e-04,-6.4317473328755128e-04},
{-4.5793392919712261e-04,-2.1744186189341037e-04,2.5912834893712798e-03},
{1.5850650475339276e-03,-6.4434145921806031e-06,-5.7440449281686960e-04},
{-2.0204313429923672e-03,6.3428280954377821e-05,2.5115932933766497e-03},
{-7.6107091738481837e-05,6.5742688995404971e-04,-2.9040212591161766e-04}};

/* Unit test constants */
const unsigned int NATOMS = 108;
const unsigned int MASS = 39.948;
const unsigned int EPS = 1e-7;

/* Expected results */
const double EXPECTED_EKIN = 6.2768069712;
const double EXPECTED_TEMP = 19.6798005947;

#endif