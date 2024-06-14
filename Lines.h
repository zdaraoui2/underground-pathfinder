#include "Graph.h"

void initialiseStations(Graph &graph)
{
    graph.addStation("Oxford Circus");
    graph.addStation("Green Park");
    graph.addStation("Victoria");
    graph.addStation("Bond Street");
    graph.addStation("Baker Street");
    graph.addStation("Waterloo");
    graph.addStation("Piccadilly Circus");
    graph.addStation("Leicester Square");
    graph.addStation("Covent Garden");
    graph.addStation("Holborn");
    graph.addStation("Charing Cross");
    graph.addStation("Embankment");
    graph.addStation("Temple");
    graph.addStation("Blackfriars");
    graph.addStation("St Pauls");
    graph.addStation("Bank");
    graph.addStation("Moorgate");
    graph.addStation("Liverpool Street");
    graph.addStation("Barbican");
    graph.addStation("Farringdon");
    graph.addStation("Kings Cross St Pancras");
    graph.addStation("Euston");
    graph.addStation("Russell Square");
    graph.addStation("Paddington");
    graph.addStation("Edgware Road");
    graph.addStation("Warren Street");
    graph.addStation("Tottenham Court Road");
    graph.addStation("Chancery Lane");
    graph.addStation("Great Portland Street");
    graph.addStation("Euston Square");
    graph.addStation("Bayswater");
    graph.addStation("Notting Hill Gate");
    graph.addStation("High Street Kensington");
    graph.addStation("South Kensington");
    graph.addStation("Sloane Square");
    graph.addStation("Westminster");
    graph.addStation("Mansion House");
    graph.addStation("Cannon Street");
    graph.addStation("Monument");
    graph.addStation("Tower Hill");
    graph.addStation("Aldgate");
    graph.addStation("Marylebone");
    graph.addStation("Regents Park");
    graph.addStation("Goodge Street");
    graph.addStation("Hyde Park Corner");
    graph.addStation("Gloucester Road");
    graph.addStation("Southwark");
    graph.addStation("London Bridge");
    graph.addStation("Old Street");
    graph.addStation("Aldgate East");
    graph.addStation("St James Park");
}

void initialiseCentralLine(Graph &graph)
{
    graph.addConnection("Oxford Circus", "Tottenham Court Road", 1, "Central");
    graph.addConnection("Tottenham Court Road", "Holborn", 1, "Central");
    graph.addConnection("Holborn", "Chancery Lane", 1, "Central");
    graph.addConnection("Chancery Lane", "St Pauls", 1, "Central");
    graph.addConnection("St Pauls", "Bank", 1, "Central");
    graph.addConnection("Bank", "Liverpool Street", 1, "Central");
    graph.addConnection("Liverpool Street", "Moorgate", 1, "Central");
}

void initialiseVictoriaLine(Graph &graph)
{
    graph.addConnection("Victoria", "Green Park", 2, "Victoria");
    graph.addConnection("Green Park", "Oxford Circus", 1, "Victoria");
    graph.addConnection("Oxford Circus", "Warren Street", 1, "Victoria");
    graph.addConnection("Warren Street", "Euston", 1, "Victoria");
    graph.addConnection("Euston", "Kings Cross St Pancras", 1, "Victoria");
}

void initialiseBakerlooLine(Graph &graph)
{
    graph.addConnection("Paddington", "Edgware Road", 1, "Bakerloo");
    graph.addConnection("Edgware Road", "Marylebone", 1, "Bakerloo");
    graph.addConnection("Marylebone", "Baker Street", 1, "Bakerloo");
    graph.addConnection("Baker Street", "Regents Park", 1, "Bakerloo");
    graph.addConnection("Regents Park", "Oxford Circus", 1, "Bakerloo");
    graph.addConnection("Oxford Circus", "Piccadilly Circus", 1, "Bakerloo");
    graph.addConnection("Piccadilly Circus", "Charing Cross", 1, "Bakerloo");
    graph.addConnection("Charing Cross", "Embankment", 1, "Bakerloo");
    graph.addConnection("Embankment", "Waterloo", 1, "Bakerloo");
}

void initialisePiccadillyLine(Graph &graph)
{
    graph.addConnection("Kings Cross St Pancras", "Russell Square", 1, "Piccadilly");
    graph.addConnection("Russell Square", "Holborn", 1, "Piccadilly");
    graph.addConnection("Holborn", "Covent Garden", 1, "Piccadilly");
    graph.addConnection("Covent Garden", "Leicester Square", 1, "Piccadilly");
    graph.addConnection("Leicester Square", "Piccadilly Circus", 1, "Piccadilly");
    graph.addConnection("Piccadilly Circus", "Green Park", 1, "Piccadilly");
    graph.addConnection("Green Park", "Hyde Park Corner", 1, "Piccadilly");
}

void initialiseJubileeLine(Graph &graph)
{
    graph.addConnection("Baker Street", "Bond Street", 1, "Jubilee");
    graph.addConnection("Bond Street", "Green Park", 1, "Jubilee");
    graph.addConnection("Green Park", "Westminster", 1, "Jubilee");
    graph.addConnection("Westminster", "Waterloo", 1, "Jubilee");
    graph.addConnection("Waterloo", "Southwark", 1, "Jubilee");
}

void initialiseCircleLine(Graph &graph)
{
    graph.addConnection("Edgware Road", "Paddington", 1, "Circle");
    graph.addConnection("Paddington", "Bayswater", 1, "Circle");
    graph.addConnection("Bayswater", "Notting Hill Gate", 1, "Circle");
    graph.addConnection("Notting Hill Gate", "High Street Kensington", 1, "Circle");
    graph.addConnection("High Street Kensington", "Gloucester Road", 1, "Circle");
    graph.addConnection("Gloucester Road", "South Kensington", 1, "Circle");
    graph.addConnection("South Kensington", "Sloane Square", 1, "Circle");
    graph.addConnection("Sloane Square", "Victoria", 1, "Circle");
    graph.addConnection("Victoria", "St James Park", 1, "Circle");
    graph.addConnection("St James Park", "Westminster", 1, "Circle");
    graph.addConnection("Westminster", "Embankment", 1, "Circle");
    graph.addConnection("Embankment", "Temple", 1, "Circle");
    graph.addConnection("Temple", "Blackfriars", 1, "Circle");
    graph.addConnection("Blackfriars", "Mansion House", 1, "Circle");
    graph.addConnection("Mansion House", "Cannon Street", 1, "Circle");
    graph.addConnection("Cannon Street", "Monument", 1, "Circle");
    graph.addConnection("Monument", "Tower Hill", 1, "Circle");
    graph.addConnection("Tower Hill", "Aldgate", 1, "Circle");
    graph.addConnection("Aldgate", "Liverpool Street", 1, "Circle");
    graph.addConnection("Liverpool Street", "Moorgate", 1, "Circle");
    graph.addConnection("Moorgate", "Barbican", 1, "Circle");
    graph.addConnection("Barbican", "Farringdon", 1, "Circle");
    graph.addConnection("Farringdon", "Kings Cross St Pancras", 1, "Circle");
    graph.addConnection("Kings Cross St Pancras", "Euston Square", 1, "Circle");
    graph.addConnection("Euston Square", "Great Portland Street", 1, "Circle");
    graph.addConnection("Great Portland Street", "Baker Street", 1, "Circle");
    graph.addConnection("Baker Street", "Edgware Road", 1, "Circle");
}

void initialiseDistrictLine(Graph &graph)
{
    graph.addConnection("Paddington", "Bayswater", 1, "District");
    graph.addConnection("Bayswater", "Notting Hill Gate", 1, "District");
    graph.addConnection("Notting Hill Gate", "High Street Kensington", 1, "District");
    graph.addConnection("High Street Kensington", "South Kensington", 1, "District");
    graph.addConnection("South Kensington", "Sloane Square", 1, "District");
    graph.addConnection("Sloane Square", "Victoria", 1, "District");
    graph.addConnection("Victoria", "St James Park", 1, "District");
    graph.addConnection("St James Park", "Westminster", 1, "District");
    graph.addConnection("Westminster", "Embankment", 1, "District");
    graph.addConnection("Embankment", "Temple", 1, "District");
    graph.addConnection("Temple", "Blackfriars", 1, "District");
    graph.addConnection("Blackfriars", "Mansion House", 1, "District");
    graph.addConnection("Mansion House", "Cannon Street", 1, "District");
    graph.addConnection("Cannon Street", "Monument", 1, "District");
    graph.addConnection("Monument", "Tower Hill", 1, "District");
    graph.addConnection("Tower Hill", "Aldgate East", 1, "District");
}

void initialiseNorthernLine(Graph &graph)
{
    graph.addConnection("Kings Cross St Pancras", "Euston", 1, "Northern");
    graph.addConnection("Euston", "Warren Street", 1, "Northern");
    graph.addConnection("Warren Street", "Goodge Street", 1, "Northern");
    graph.addConnection("Goodge Street", "Tottenham Court Road", 1, "Northern");
    graph.addConnection("Tottenham Court Road", "Leicester Square", 1, "Northern");
    graph.addConnection("Leicester Square", "Charing Cross", 1, "Northern");
    graph.addConnection("Charing Cross", "Embankment", 1, "Northern");
    graph.addConnection("Embankment", "Waterloo", 1, "Northern");
    graph.addConnection("Waterloo", "Southwark", 1, "Northern");
    graph.addConnection("Southwark", "London Bridge", 1, "Northern");
    graph.addConnection("London Bridge", "Bank", 1, "Northern");
    graph.addConnection("Bank", "Moorgate", 1, "Northern");
    graph.addConnection("Moorgate", "Old Street", 1, "Northern");
}

void initialiseMetropolitanLine(Graph &graph)
{
    graph.addConnection("Aldgate", "Liverpool Street", 1, "Metropolitan");
    graph.addConnection("Liverpool Street", "Moorgate", 1, "Metropolitan");
    graph.addConnection("Moorgate", "Barbican", 1, "Metropolitan");
    graph.addConnection("Barbican", "Farringdon", 1, "Metropolitan");
    graph.addConnection("Farringdon", "Kings Cross St Pancras", 1, "Metropolitan");
    graph.addConnection("Kings Cross St Pancras", "Euston Square", 1, "Metropolitan");
    graph.addConnection("Euston Square", "Great Portland Street", 1, "Metropolitan");
    graph.addConnection("Great Portland Street", "Baker Street", 1, "Metropolitan");
}

void initialiseElizabethLine(Graph &graph)
{
    graph.addConnection("Paddington", "Bond Street", 1, "Elizabeth");
    graph.addConnection("Bond Street", "Tottenham Court Road", 1, "Elizabeth");
    graph.addConnection("Tottenham Court Road", "Farringdon", 1, "Elizabeth");
    graph.addConnection("Farringdon", "Liverpool Street", 1, "Elizabeth");
}
