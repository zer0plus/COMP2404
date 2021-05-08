fp: main.o Record.o ReportGenerator.o Map.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h ReportData.h SubRegionGenerator.o Dict.h Control.o View.o FarmsByRegionGenerator.o ChangeByYearGenerator.o
	g++ -o fp main.o Record.o ReportGenerator.o SubRegionGenerator.o Control.o View.o FarmsByRegionGenerator.o ChangeByYearGenerator.o

main.o: main.cc Record.h ReportGenerator.h Map.h CompareBehaviour.h AscBehaviour.h DescBehaviour.h ReportData.h SubRegionGenerator.h Dict.h Control.h View.h FarmsByRegionGenerator.h ChangeByYearGenerator.h
	g++ -g -c main.cc

Record.o: Record.cc Record.h
	g++ -g -c Record.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h
	g++ -g -c ReportGenerator.cc

SubRegionGenerator.o: SubRegionGenerator.cc SubRegionGenerator.h Dict.h
	g++ -g -c SubRegionGenerator.cc

FarmsByRegionGenerator.o: FarmsByRegionGenerator.cc FarmsByRegionGenerator.h Dict.h
	g++ -g -c FarmsByRegionGenerator.cc

ChangeByYearGenerator.o: ChangeByYearGenerator.cc ChangeByYearGenerator.h Dict.h
	g++ -g -c ChangeByYearGenerator.cc

View.o: View.cc View.h
	g++ -g -c View.cc

Control.o: Control.cc Control.h
	g++ -g -c Control.cc

clean:
	rm -f *.o fp