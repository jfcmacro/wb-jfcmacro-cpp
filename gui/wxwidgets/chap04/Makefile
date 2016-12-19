.phony: clean

CXXFLAGS=-g `wx-config --cxxflags`
LDFLAGS=`wx-config --libs`
EXECUTABLES=minimal dialog wxPanelExample wxNotebookExample \
	wxScrolledWindowExample wxSplitterWindowExample

all: $(EXECUTABLES)

minimal: minimal.o
	$(CXX) -o $@ $^ $(LDFLAGS)

minimal.o: minimal.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $<

dialog: dialog.o
	$(CXX) -o $@ $^ $(LDFLAGS)

dialog.o: dialog.cpp mondrian.xpm

wxPanelExample: wxPanelExample.o
	$(CXX) -o $@ $^ $(LDFLAGS)

wxPanelExample.o: wxPanelExample.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $<

wxNotebookExample: wxNotebookExample.o
	$(CXX) -o $@ $^ $(LDFLAGS)

wxNotebookExample.o: wxNotebookExample.cpp mondrian.xpm copy.xpm cut.xpm paste.xpm
	$(CXX) $(CXXFLAGS) -c $<

wxScrolledWindowExample: wxScrolledWindowExample.o
	$(CXX) -o $@ $^ $(LDFLAGS)

wxScrolledWindowExample.o: wxScrolledWindowExample.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $<

wxSplitterWindowExample: wxSplitterWindowExample.o
	$(CXX) -o $@ $^ $(LDFLAGS)

wxSplitterWindowExample.o: wxSplitterWindowExample.cpp mondrian.xpm
	$(CXX) $(CXXFLAGS) -c $< 

clean:
	rm -f *.o $(EXECUTABLES)
