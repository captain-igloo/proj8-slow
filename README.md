We have an application that runs significantly slower when using proj 8 than it did with proj 6.

It transforms points to/from NZMG (epsg 27200) using the proj string found here: https://spatialreference.org/ref/epsg/27200/proj4/ .  If I use the proj string from https://epsg.io/27200, proj 8 is just as fast as proj 6.

The following transforms a number of points from NZMG to WGS84 with proj6 and proj8:

```
git clone https://github.com/captain-igloo/proj8-slow
cd proj8-slow

docker build -t test-proj6 -f proj6.Dockerfile .
docker build -t test-proj8 -f proj8.Dockerfile .

time docker run test-proj6 /proj-slow/a.out
time docker run test-proj8 /proj-slow/a.out
```

The output I get is:

```
$ time docker run test-proj8 /proj-slow/a.out

real	0m18.300s
user	0m0.014s
sys	0m0.024s

$ time docker run test-proj6 /proj-slow/a.out

real	0m3.040s
user	0m0.024s
sys	0m0.018s
```

So proj 6 is about six times faster than proj 8 for me.

see issue https://github.com/OSGeo/PROJ/issues/3240

